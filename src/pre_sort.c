/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:35:02 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 13:43:52 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operator.h"
#include "../include/sort.h"
#include <stddef.h>

static int	get_min_data(t_stack stack[2])
{
	t_node	*cur;
	int		min;

	cur = stack[HEAD].ptr;
	min = cur->data;
	while (cur != NULL)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	return (min);
}

static int	get_max_data(t_stack stack[2])
{
	t_node	*cur;
	int		max;

	cur = stack[HEAD].ptr;
	max = cur->data;
	while (cur != NULL)
	{
		if (max < cur->data)
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

static void	divide_three_parts(t_stack stacks[2][2], int pivot[2])
{
	int	to_check;

	to_check = stacks[ST_A][HEAD].size;
	while (to_check > 3)
	{
		if (stacks[ST_A][HEAD].ptr->data < pivot[PV_A])
		{
			pb(stacks);
			if (stacks[ST_A][HEAD].ptr->data >= pivot[PV_A]
				&& stacks[ST_B][HEAD].ptr->data < pivot[PV_B])
			{
				if (stacks[ST_B][HEAD].size > 1)
					rr(stacks);
				else
					ra(stacks);
				to_check--;
			}
			else if (stacks[ST_B][HEAD].size > 1
				&& stacks[ST_B][HEAD].ptr->data < pivot[PV_B])
				rb(stacks);
		}
		else
			ra(stacks);
		to_check--;
	}
}

static void	sort_minimum(t_stack stacks[2][2], int limit[2])
{
	if (stacks[ST_A][HEAD].ptr->data == limit[MAX])
		ra(stacks);
	else if (stacks[ST_A][TAIL].ptr->data != limit[MAX])
		rra(stacks);
	if (stacks[ST_A][HEAD].ptr->next != NULL
		&& stacks[ST_A][HEAD].ptr->data > stacks[ST_A][HEAD].ptr->next->data)
		sa(stacks);
}

int	pre_sort(t_stack stacks[2][2], int pivot[2], int limit[2])
{
	if (stacks[ST_A][HEAD].size == 1)
		return (1);
	else if (stacks[ST_A][HEAD].size > 3)
		divide_three_parts(stacks, pivot);
	limit[MIN] = get_min_data(stacks[ST_A]);
	limit[MAX] = get_max_data(stacks[ST_A]);
	sort_minimum(stacks, limit);
	return (is_sorted_stack(stacks));
}
