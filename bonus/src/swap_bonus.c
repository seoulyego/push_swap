/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:23 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:26:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct_bonus.h"
#include <stddef.h>

static void	swap_element(t_stack stack[2])
{
	t_node	*node_prev;
	t_node	*node_next;
	t_node	*node_bottom;

	if (stack[HEAD].stack_size == 0 || stack[HEAD].stack_size == 1)
		return ;
	node_prev = stack[HEAD].ptr;
	node_next = node_prev->next;
	node_prev->next = node_next->next;
	node_next->next = node_prev;
	stack[HEAD].ptr = node_next;
	node_bottom = stack[HEAD].ptr;
	while (node_bottom->next != NULL)
		node_bottom = node_bottom->next;
	stack[TAIL].ptr = node_bottom;
}

void	sa(t_stack stacks[2][2])
{
	swap_element(stacks[ST_A]);
}

void	sb(t_stack stacks[2][2])
{
	swap_element(stacks[ST_B]);
}

void	ss(t_stack stacks[2][2])
{
	swap_element(stacks[ST_A]);
	swap_element(stacks[ST_B]);
}
