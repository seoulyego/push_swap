/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:23 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/12 17:46:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/print.h"
#include <stddef.h>

static int	swap_element(t_stack stack[2])
{
	t_node	*node_prev;
	t_node	*node_next;
	t_node	*node_bottom;

	if (stack[HEAD].size < 2)
		return (0);
	node_prev = stack[HEAD].ptr;
	node_next = node_prev->next;
	node_prev->next = node_next->next;
	node_next->next = node_prev;
	stack[HEAD].ptr = node_next;
	node_bottom = stack[HEAD].ptr;
	while (node_bottom->next != NULL)
		node_bottom = node_bottom->next;
	stack[TAIL].ptr = node_bottom;
	return (1);
}

void	sa(t_stack stacks[2][2])
{
	int	result;

	result = swap_element(stacks[ST_A]);
	if (result)
		print_result("sa");
}

void	sb(t_stack stacks[2][2])
{
	int	result;

	result = swap_element(stacks[ST_B]);
	if (result)
		print_result("sb");
}

void	ss(t_stack stacks[2][2])
{
	int	result_sa;
	int	result_sb;

	result_sa = swap_element(stacks[ST_A]);
	result_sb = swap_element(stacks[ST_B]);
	if (result_sa && result_sb)
		print_result("ss");
	else if (result_sa)
		print_result("sa");
	else if (result_sb)
		print_result("sb");
}
