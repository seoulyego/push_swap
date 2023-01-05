/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:19:22 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 20:37:35 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "struct.h"

enum e_operation {
	OP_PA,
	OP_PB,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_FAIL
};

void	pa(t_stack stacks[2][2]);
void	pb(t_stack stacks[2][2]);
void	sa(t_stack stacks[2][2]);
void	sb(t_stack stacks[2][2]);
void	ss(t_stack stacks[2][2]);
void	ra(t_stack stacks[2][2]);
void	rb(t_stack stacks[2][2]);
void	rr(t_stack stacks[2][2]);
void	rra(t_stack stacks[2][2]);
void	rrb(t_stack stacks[2][2]);
void	rrr(t_stack stacks[2][2]);
void	ra_and_rrb(t_stack stacks[2][2]);
void	rra_and_rb(t_stack stacks[2][2]);
#endif
