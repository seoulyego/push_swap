/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:23 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/13 16:52:37 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	swap_element(t_stack *head)
{
	t_stack	*node_prev;
	t_stack	*node_next;
	t_stack	*tmp;

	if (head->stack_size == 0 || head->stack_size == 1)
		return ;
	node_prev = head->next;
	node_next = node_prev->next;
	tmp = node_next->next;
	node_prev->next = tmp;
	node_next->next = node_prev;
	head->next = node_next;
}

void	sa(t_stack *head_a)
{
	swap_element(head_a);
}

void	sb(t_stack *head_b)
{
	swap_element(head_b);
}

void	ss(t_stack *head_a, t_stack *head_b)
{
	sa(head_a);
	sb(head_b);
}
