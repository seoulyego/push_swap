/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:35:58 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/13 07:43:46 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../include/print.h"
#include <stddef.h>

static int	push_element(t_stack stack_from[2], t_stack stack_to[2])
{
	t_node	*node_tmp;

	if (stack_from->size == 0)
		return (0);
	node_tmp = stack_from[HEAD].ptr->next;
	stack_from[HEAD].ptr->next = stack_to[HEAD].ptr;
	stack_to[HEAD].ptr = stack_from[HEAD].ptr;
	stack_to[HEAD].size++;
	stack_from[HEAD].ptr = node_tmp;
	stack_from[HEAD].size--;
	if (stack_to[TAIL].ptr == NULL)
		stack_to[TAIL].ptr = get_prev_element(&stack_to[HEAD], NULL);
	if (stack_from[HEAD].ptr == NULL)
		stack_from[TAIL].ptr = NULL;
	return (1);
}

void	pa(t_stack stacks[2][2])
{
	int	result_pa;

	result_pa = push_element(stacks[ST_B], stacks[ST_A]);
	if (result_pa)
		print_result("pa");
}

void	pb(t_stack stacks[2][2])
{
	int	result_pb;

	result_pb = push_element(stacks[ST_A], stacks[ST_B]);
	if (result_pb)
		print_result("pb");
}
