/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:47:57 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 21:41:35 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"

void	get_min_rot_count(t_stack stacks[2][2], int limit[2], int rot[2])
{
	t_node	*cur_b;
	size_t	index;
	size_t	index_std;
	int		rot_tmp[2];

	cur_b = stacks[ST_B][HEAD].ptr;
	index_std = stacks[ST_B][HEAD].size / 2;
	index = 0;
	while (index < stacks[ST_B][HEAD].size)
	{
		rot_tmp[CNT_A] = set_rot_count(stacks, limit, cur_b->data);
		rot_tmp[CNT_B]
			= index - (stacks[ST_B][HEAD].size * (index > index_std));
		if (index == 0 || change_rot_count(rot, rot_tmp))
		{
			rot[CNT_A] = rot_tmp[CNT_A];
			rot[CNT_B] = rot_tmp[CNT_B];
		}
		cur_b = cur_b->next;
		index++;
	}
}

void	match_insert_position(t_stack stacks[2][2], int limit[2], int rot[2])
{
	static t_rotate	f_rotate[3][3];
	static int		initialized;
	static int		state[2];

	if (!initialized++)
		init_f_table(f_rotate);
	if ((rot[CNT_A] < 0 && rot[CNT_B] > 0)
		|| (rot[CNT_A] > 0 && rot[CNT_B] < 0))
		optimize_opposite_direction
			(stacks[ST_A][HEAD].size, stacks[ST_B][HEAD].size, rot);
	while (rot[CNT_A] != 0 || rot[CNT_B] != 0)
	{
		set_state(state, rot);
		f_rotate[state[CNT_A]][state[CNT_B]](stacks);
		rot[CNT_A] += state[CNT_A] - 1;
		rot[CNT_B] += state[CNT_B] - 1;
	}
}
