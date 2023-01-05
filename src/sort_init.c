/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:35:39 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 21:38:41 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"

int	set_rot_count(t_stack stacks[2][2], int limit[2], int data_ref)
{
	t_node	*cur;
	int		location;

	cur = stacks[ST_A][HEAD].ptr;
	if (data_ref < limit[MIN])
		return (locate_limit(stacks, limit, MIN));
	else if (data_ref >= limit[MAX])
		return (locate_limit(stacks, limit, MAX));
	else
		return (locate_insert_point(stacks, data_ref));
}

void	init_f_table(t_rotate f_rotate[3][3])
{
	f_rotate[0][0] = rrr;
	f_rotate[0][1] = rra;
	f_rotate[0][2] = rra_and_rb;
	f_rotate[1][0] = rrb;
	f_rotate[1][1] = NULL;
	f_rotate[1][2] = rb;
	f_rotate[2][0] = ra_and_rrb;
	f_rotate[2][1] = ra;
	f_rotate[2][2] = rr;
}

void	set_state(int state[2], int rot[2])
{
	if (rot[CNT_A] < 0)
		state[CNT_A] = 0;
	else if (rot[CNT_A] == 0)
		state[CNT_A] = 1;
	else if (rot[CNT_A] > 0)
		state[CNT_A] = 2;
	if (rot[CNT_B] < 0)
		state[CNT_B] = 0;
	else if (rot[CNT_B] == 0)
		state[CNT_B] = 1;
	else if (rot[CNT_B] > 0)
		state[CNT_A] = 2;
}
