/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:58:24 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 05:45:56 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include <stdlib.h>

int	stack_push(int data, t_stack stack[2])
{
	t_node	*node_new;

	node_new = malloc(sizeof(t_stack));
	if (node_new == NULL)
		return (0);
	node_new->data = data;
	node_new->next = stack[HEAD].ptr;
	stack[HEAD].ptr = node_new;
	stack[HEAD].size++;
	if (stack[TAIL].ptr == NULL)
		stack[TAIL].ptr = stack[HEAD].ptr;
	return (1);
}

t_node	*get_prev_element(t_stack *head, void *data_ref)
{
	t_node	*node_last;

	node_last = head->ptr;
	if (node_last == NULL)
		return (NULL);
	while (node_last->next != data_ref)
		node_last = node_last->next;
	return (node_last);
}

static void	free_stack(t_stack stack[2])
{
	t_node	*node_cur;
	t_node	*node_tmp;

	if (stack[HEAD].ptr == NULL)
		return ;
	node_cur = stack[HEAD].ptr;
	while (node_cur != NULL)
	{
		node_tmp = node_cur->next;
		free(node_cur);
		stack[HEAD].size--;
		node_cur = node_tmp;
	}
	stack[HEAD].ptr = NULL;
	stack[TAIL].ptr = NULL;
}

void	clear_stacks(t_stack stacks[2][2])
{
	free_stack(stacks[ST_A]);
	free_stack(stacks[ST_B]);
}
