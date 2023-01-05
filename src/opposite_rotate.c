/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:34:43 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 20:36:59 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operator.h"

void	ra_and_rrb(t_stack stacks[2][2])
{
	ra(stacks);
	rrb(stacks);
}

void	rra_and_rb(t_stack stacks[2][2])
{
	rra(stacks);
	rb(stacks);
}
