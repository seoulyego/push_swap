/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:35:58 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/06 20:07:14 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	push_node(t_stack *head_to, t_stack *head_from);

void	pa(t_stack *head_b, t_stack *head_a)
{
	t_stack	*tmp;

	if (head_b->stack_size == 0 || head_a->stack_size == 0)
		return ;
	tmp = head_b->next->next;
	head_b->next->next = head_a->next;
	head_a->next = head_b->next;
	head_b->next = tmp;
	head_b->stack_size--;
	head_a->stack_size++;
}

void	pb(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp;

	if (head_a->stack_size == 0 || head_b->stack_size == 0)
		return ;
	tmp = head_a->next->next;
	head_a->next->next = head_b->next;
	head_b->next = head_a->next;
	head_a->next = tmp;
	head_a->stack_size--;
	head_b->stack_size++;
}
