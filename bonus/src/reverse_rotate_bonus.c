/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/12 18:01:43 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack_bonus.h"
#include <stddef.h>

static void	reverse_rotate_element(t_stack stack[2])
{
	t_node	*node_top;
	t_node	*node_last;
	t_node	*node_tmp;

	if (stack[HEAD].size < 2)
		return ;
	node_top = stack[HEAD].ptr;
	node_last = stack[TAIL].ptr;
	node_tmp = get_prev_element(&stack[HEAD], node_last);
	node_last->next = node_top;
	node_tmp->next = NULL;
	stack[HEAD].ptr = node_last;
	stack[TAIL].ptr = node_tmp;
}

void	rra(t_stack stacks[2][2])
{
	reverse_rotate_element(stacks[ST_A]);
}

void	rrb(t_stack stacks[2][2])
{
	reverse_rotate_element(stacks[ST_B]);
}

void	rrr(t_stack stacks[2][2])
{
	reverse_rotate_element(stacks[ST_A]);
	reverse_rotate_element(stacks[ST_B]);
}
