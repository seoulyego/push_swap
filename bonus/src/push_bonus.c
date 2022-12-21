/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:35:58 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/13 16:52:13 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	push_element(t_stack *head_from, t_stack *head_to)
{
	t_stack	*tmp;

	if (head_from->stack_size == 0)
		return ;
	tmp = head_from->next->next;
	head_from->next->next = head_to->next;
	head_to->next = head_from->next;
	head_from->next = tmp;
	head_from->stack_size--;
	head_to->stack_size++;
}

void	pa(t_stack *head_b, t_stack *head_a)
{
	push_element(head_b, head_a);
}

void	pb(t_stack *head_a, t_stack *head_b)
{
	push_element(head_a, head_b);
}
