/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/09 21:26:45 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/print.h"
//
// #include "../include/print_test.h"
// #include <stdio.h>
// extern int	g_oper_count;

static int	rotate_element(t_stack stack[2])
{
	t_node	*node_top;
	t_node	*node_last;

	if (stack[HEAD].size == 0 || stack[HEAD].size == 1)
		return (0);
	node_top = stack[HEAD].ptr;
	node_last = stack[TAIL].ptr;
	stack[HEAD].ptr = node_top->next;
	node_last->next = node_top;
	node_top->next = NULL;
	stack[TAIL].ptr = node_top;
	return (1);
}

void	ra(t_stack stacks[2][2])
{
	int	result;

	result = rotate_element(stacks[ST_A]);
	if (result)
		print_result("ra");
}

void	rb(t_stack stacks[2][2])
{
	int	result;

	result = rotate_element(stacks[ST_B]);
	if (result)
		print_result("rb");
}

void	rr(t_stack stacks[2][2])
{
	int	result;

	result = (rotate_element(stacks[ST_A])
			&& rotate_element(stacks[ST_B]));
	if (result)
		print_result("rr");
}
