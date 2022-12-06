/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:23 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/06 21:37:29 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	swap_link(t_stack *node_prev, t_stack *node_next)
{
	t_stack	*tmp;

	tmp = node_next->next;
	node_prev->next = tmp;
	node_next->next = node_prev;
}

void	sa(t_stack *head_a, unsigned int stack_size)
{
	t_stack	*prev;
	t_stack	*next;

	if (stack_size == 0 || stack_size == 1)
		return ;
	prev = head_a->next;
	next = prev->next;
	swap_link(prev, next);
	head_a->next = next;
}

void	sb(t_stack *head_b, unsigned int stack_size)
{
	t_stack	*prev;
	t_stack	*next;

	if (stack_size == 0 || stack_size == 1)
		return ;
	prev = head_b->next;
	next = prev->next;
	swap_link(prev, next);
	head_b->next = next;
}

void	ss(t_stack *head_a, t_stack *head_b)
{
	sa(head_a, head_a->stack_size);
	sb(head_b, head_b->stack_size);
}
