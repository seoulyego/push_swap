/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:55:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/10 13:20:10 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/print.h"
#include <stddef.h>

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
	int	result_ra;
	int	result_rb;

	result_ra = rotate_element(stacks[ST_A]);
	result_rb = rotate_element(stacks[ST_B]);
	if (result_ra && result_rb)
		print_result("rr");
	else if (result_ra)
		print_result("ra");
	else if (result_rb)
		print_result("rb");
}
