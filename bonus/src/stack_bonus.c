/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:58:24 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:25:57 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct_bonus.h"
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
	stack[HEAD].stack_size++;
	if (stack[TAIL].ptr == NULL)
		stack[TAIL].ptr = stack[HEAD].ptr;
	return (1);
}

int	stack_pop(t_stack stack[2])
{
	t_node	*node_del;
	int		data_del;

	if (stack[HEAD].stack_size == 0)
		return (0);
	node_del = stack[HEAD].ptr;
	if (node_del == stack[TAIL].ptr)
		stack[TAIL].ptr = NULL;
	data_del = node_del->data;
	stack[HEAD].ptr = node_del->next;
	if (node_del != NULL)
		free(node_del);
	stack[HEAD].stack_size--;
	return (data_del);
}

t_node	*get_prev_element(t_stack *head, void *data_ref)
{
	t_node	*node_last;

	node_last = head->ptr;
	while (node_last->next != data_ref)
		node_last = node_last->next;
	return (node_last);
}

void	free_stack(t_stack stack[2])
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
		stack[HEAD].stack_size--;
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
