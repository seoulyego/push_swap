/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:35:39 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/13 08:10:28 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"
#include <stddef.h>

int	set_rot_count(t_stack stacks[2][2], int limit[2], int data_ref)
{
	t_node	*cur;

	cur = stacks[ST_A][HEAD].ptr;
	if (limit[MIN] < data_ref && data_ref < limit[MAX])
		return (locate_insert_point(stacks, data_ref));
	return (locate_limit(stacks, limit, data_ref > limit[MAX]));
}

void	init_f_table(t_rotate f_rotate[3][3])
{
	f_rotate[0][0] = rrr;
	f_rotate[0][1] = rrb;
	f_rotate[0][2] = ra_and_rrb;
	f_rotate[1][0] = rra;
	f_rotate[1][1] = NULL;
	f_rotate[1][2] = ra;
	f_rotate[2][0] = rra_and_rb;
	f_rotate[2][1] = rb;
	f_rotate[2][2] = rr;
}

void	set_state(int state[2], int rot[2])
{
	state[ST_A] = 0 + (rot[ST_A] >= 0) + (rot[ST_A] > 0);
	state[ST_B] = 0 + (rot[ST_B] >= 0) + (rot[ST_B] > 0);
}
