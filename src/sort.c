/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:25:47 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 21:40:10 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../include/operator.h"

void	insert_element(t_stack stacks[2][2], int rot[2])
{
	pa(stacks);
}

void	push_swap(t_stack stacks[2][2], int pivot[2])
{
	static int	limit[2];
	static int	rotation[2];

	if (is_sorted_stack(stacks))
		return ;
	if (pre_sort(stacks, pivot, limit))
		return ;
}
