/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/13 20:55:56 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include <stddef.h>

t_stack	*get_last_element(t_stack *head)
{
	t_stack	*node_last;

	node_last = head;
	while (node_last->next != NULL)
		node_last = node_last->next;
	return (node_last);
}

static void	rotate_element(t_stack *head)
{
	t_stack	*node_top;
	t_stack	*node_last;

	if (head->stack_size == 0 || head->stack_size == 1)
		return ;
	node_top = head->next;
	node_last = get_last_element(head);
	head->next = node_top->next;
	node_last->next = node_top;
	node_top->next = NULL;
}

void	ra(t_stack *head_a)
{
	rotate_element(head_a);
}

void	rb(t_stack *head_b)
{
	rotate_element(head_b);
}

void	rr(t_stack *head_a, t_stack *head_b)
{
	ra(head_a);
	rb(head_b);
}
