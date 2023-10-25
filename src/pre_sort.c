/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:35:02 by yeongo            #+#    #+#             */
/*   Updated: 2023/02/09 10:21:14 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operator.h"
#include "../include/sort.h"
#include <stddef.h>

static void	get_limit_data(t_stack stack[2], int limit[2])
{
	t_node	*cur;

	cur = stack[HEAD].ptr;
	if (cur == NULL)
		return ;
	limit[MIN] = cur->data;
	limit[MAX] = cur->data;
	while (cur != NULL)
	{
		if (limit[MIN] > cur->data)
			limit[MIN] = cur->data;
		if (limit[MAX] < cur->data)
			limit[MAX] = cur->data;
		cur = cur->next;
	}
}

static void	divide_three_parts(t_stack stacks[2][2], int pivot[2])
{
	int	to_check;

	to_check = stacks[ST_A][HEAD].size;
	while (to_check > 0)
	{
		if (stacks[ST_A][HEAD].ptr->data < pivot[ST_A])
		{
			pb(stacks);
			if (stacks[ST_A][HEAD].ptr->data >= pivot[ST_A])
			{
				if (stacks[ST_B][HEAD].ptr->data < pivot[ST_B])
					rr(stacks);
				else
					ra(stacks);
				to_check--;
			}
			else if (stacks[ST_B][HEAD].ptr->data < pivot[ST_B])
				rb(stacks);
		}
		else
			ra(stacks);
		to_check--;
	}
}

static void	left_minimum_element(t_stack stacks[2][2])
{
	t_node	*cur;
	int		sorted;

	cur = stacks[ST_A][HEAD].ptr;
	sorted = 0;
	while (cur->next != NULL && sorted < stacks[ST_A][HEAD].size)
	{
		if (cur->data > cur->next->data)
			sorted = 0;
		sorted++;
		cur = cur->next;
	}
	while (stacks[ST_A][HEAD].size > 3 && stacks[ST_A][HEAD].size > sorted)
		pb(stacks);
}

static void	sort_minimum(t_stack stacks[2][2], int limit[2])
{
	int	condition_sa;
	int	condition_sb;

	if (stacks[ST_A][HEAD].ptr->data == limit[MAX])
		ra(stacks);
	else if (stacks[ST_A][TAIL].ptr->data != limit[MAX])
		rra(stacks);
	condition_sa = (stacks[ST_A][HEAD].size > 1 \
		&& stacks[ST_A][HEAD].ptr->data > stacks[ST_A][HEAD].ptr->next->data);
	condition_sb = (stacks[ST_B][HEAD].size > 1 \
		&& stacks[ST_B][HEAD].ptr->data < stacks[ST_B][HEAD].ptr->next->data);
	if (condition_sa && condition_sb)
		ss(stacks);
	else if (condition_sa)
		sa(stacks);
	else if (condition_sb)
		sb(stacks);
}

int	pre_sort(t_stack stacks[2][2], int pivot[2], int limit[2])
{
	if (stacks[ST_A][HEAD].size > 5)
		divide_three_parts(stacks, pivot);
	left_minimum_element(stacks);
	get_limit_data(stacks[ST_A], limit);
	if (stacks[ST_A][HEAD].size > 1)
		sort_minimum(stacks, limit);
	return (is_sorted_stack(stacks));
}
