/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/13 20:56:04 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include <stddef.h>

static t_stack	*get_element(t_stack *head, void *data_ref)
{
	t_stack	*node_last;

	node_last = head;
	while (node_last->next != data_ref)
		node_last = node_last->next;
	return (node_last);
}

static void	reverse_rotate_element(t_stack *head)
{
	t_stack	*node_top;
	t_stack	*node_last;
	t_stack	*node_tmp;

	if (head->stack_size == 0 || head->stack_size == 1)
		return ;
	node_top = head->next;
	node_last = get_last_element(head);
	node_tmp = get_element(head, node_last);
	node_last->next = node_top;
	head->next = node_last;
	node_tmp->next = NULL;
}

void	rra(t_stack *head_a)
{
	reverse_rotate_element(head_a);
}

void	rrb(t_stack *head_b)
{
	reverse_rotate_element(head_b);
}

void	rrr(t_stack *head_a, t_stack *head_b)
{
	rra(head_a);
	rrb(head_b);
}
