/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 05:46:02 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"

static void	rotate_element(t_stack stack[2])
{
	t_node	*node_top;
	t_node	*node_last;

	if (stack[HEAD].size == 0 || stack[HEAD].size == 1)
		return ;
	node_top = stack[HEAD].ptr;
	node_last = stack[TAIL].ptr;
	stack[HEAD].ptr = node_top->next;
	node_last->next = node_top;
	node_top->next = NULL;
	stack[TAIL].ptr = node_top;
}

void	ra(t_stack stacks[2][2])
{
	rotate_element(stacks[ST_A]);
}

void	rb(t_stack stacks[2][2])
{
	rotate_element(stacks[ST_B]);
}

void	rr(t_stack stacks[2][2])
{
	rotate_element(stacks[ST_A]);
	rotate_element(stacks[ST_B]);
}
