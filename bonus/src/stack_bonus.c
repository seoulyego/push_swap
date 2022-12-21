/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:58:24 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/13 17:22:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include <stdlib.h>

void	stack_push(int data, t_stack *head)
{
	t_stack	*node_new;

	node_new = malloc(sizeof(t_stack));
	if (node_new == NULL)
		return ;
	node_new->data = data;
	node_new->next = head->next;
	head->next = node_new;
}

int	stack_pop(t_stack *head)
{
	t_stack	*node_del;
	int		data_del;

	node_del = head->next;
	data_del = node_del->data;
	head->next = node_del->next;
	free(node_del);
	return (data_del);
}
