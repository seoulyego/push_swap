/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:35:58 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/09 21:40:30 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack_bonus.h"
#include <stddef.h>

static void	push_element(t_stack stack_from[2], t_stack stack_to[2])
{
	t_node	*node_tmp;

	if (stack_from->size == 0)
		return ;
	node_tmp = stack_from[HEAD].ptr->next;
	stack_from[HEAD].ptr->next = stack_to[HEAD].ptr;
	stack_to[HEAD].ptr = stack_from[HEAD].ptr;
	stack_to[HEAD].size++;
	stack_from[HEAD].ptr = node_tmp;
	stack_from[HEAD].size--;
	if (stack_from[TAIL].ptr == NULL)
		stack_from[TAIL].ptr = get_prev_element(&stack_from[HEAD], NULL);
	if (stack_to[TAIL].ptr == NULL)
		stack_to[TAIL].ptr = get_prev_element(&stack_to[HEAD], NULL);
}

void	pa(t_stack stacks[2][2])
{
	push_element(stacks[ST_B], stacks[ST_A]);
}

void	pb(t_stack stacks[2][2])
{
	push_element(stacks[ST_A], stacks[ST_B]);
}
