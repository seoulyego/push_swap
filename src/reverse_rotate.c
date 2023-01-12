/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/12 17:45:56 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../include/print.h"
#include <stddef.h>

static int	reverse_rotate_element(t_stack stack[2])
{
	t_node	*node_top;
	t_node	*node_last;
	t_node	*node_tmp;

	if (stack[HEAD].size < 2)
		return (0);
	node_top = stack[HEAD].ptr;
	node_last = stack[TAIL].ptr;
	node_tmp = get_prev_element(&stack[HEAD], node_last);
	node_last->next = node_top;
	node_tmp->next = NULL;
	stack[HEAD].ptr = node_last;
	stack[TAIL].ptr = node_tmp;
	return (1);
}

void	rra(t_stack stacks[2][2])
{
	int	result;

	result = reverse_rotate_element(stacks[ST_A]);
	if (result)
		print_result("rra");
}

void	rrb(t_stack stacks[2][2])
{
	int	result;

	result = reverse_rotate_element(stacks[ST_B]);
	if (result)
		print_result("rrb");
}

void	rrr(t_stack stacks[2][2])
{
	int	result_rra;
	int	result_rrb;

	result_rra = reverse_rotate_element(stacks[ST_A]);
	result_rrb = reverse_rotate_element(stacks[ST_B]);
	if (result_rra && result_rrb)
		print_result("rrr");
	else if (result_rra)
		print_result("rra");
	else if (result_rrb)
		print_result("rrb");
}
