/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:25:47 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/13 00:46:21 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"

void	insert_elements(t_stack stacks[2][2], int limit[2], int rot[2])
{
	while (stacks[ST_B][HEAD].size)
	{
		get_min_rot_count(stacks, limit, rot);
		match_insert_position(stacks, rot);
		pa(stacks);
		if (stacks[ST_A][HEAD].ptr->data < limit[MIN])
			limit[MIN] = stacks[ST_A][HEAD].ptr->data;
		else if (stacks[ST_A][HEAD].ptr->data > limit[MAX])
			limit[MAX] = stacks[ST_A][HEAD].ptr->data;
	}
	line_up_elements(stacks, limit);
}

void	push_swap(t_stack stacks[2][2], int pivot[2])
{
	static int	limit[2];
	static int	rot[2];

	if (is_sorted_stack(stacks))
		return ;
	if (pre_sort(stacks, pivot, limit))
		return ;
	insert_elements(stacks, limit, rot);
}
