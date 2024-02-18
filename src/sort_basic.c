/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:47:57 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/13 07:49:50 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"

void	get_min_rot_count(t_stack stacks[2][2], int limit[2], int rot[2])
{
	t_node	*cur_b;
	int		index;
	int		index_std;
	int		rot_tmp[2];

	cur_b = stacks[ST_B][HEAD].ptr;
	index_std = stacks[ST_B][HEAD].size / 2;
	index = 0;
	while (index < stacks[ST_B][HEAD].size)
	{
		rot_tmp[ST_A] = set_rot_count(stacks, limit, cur_b->data);
		rot_tmp[ST_B]
			= index - (stacks[ST_B][HEAD].size * (index > index_std));
		if (index == 0 || change_rot_count(rot, rot_tmp))
		{
			rot[ST_A] = rot_tmp[ST_A];
			rot[ST_B] = rot_tmp[ST_B];
		}
		cur_b = cur_b->next;
		index++;
	}
}

void	match_insert_position(t_stack stacks[2][2], int rot[2])
{
	static t_rotate	f_rotate[3][3];
	static int		initialized;
	static int		state[2];

	if (!initialized)
	{
		init_f_table(f_rotate);
		initialized = 1;
	}
	while (rot[ST_B] != 0 || rot[ST_A] != 0)
	{
		set_state(state, rot);
		f_rotate[state[ST_B]][state[ST_A]](stacks);
		rot[ST_B] -= (state[ST_B] - 1) * (rot[ST_B] != 0);
		rot[ST_A] -= (state[ST_A] - 1) * (rot[ST_A] != 0);
	}
}

void	line_up_elements(t_stack stacks[2][2], int limit[2])
{
	int	rot;
	int	sign;

	rot = locate_limit(stacks, limit, MIN);
	if (rot == 0)
		return ;
	sign = (rot > 0) - (rot < 0);
	if (sign < 0)
		while (rot) {
			rra(stacks);
			rot-= sign;
		}
	else
		while (rot) {
			ra(stacks);
			rot-= sign;
		}
}
