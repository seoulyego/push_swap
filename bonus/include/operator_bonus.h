/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:19:22 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:25:10 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_BONUS_H
# define OPERATOR_BONUS_H

# include "struct_bonus.h"

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
	OP_NONE
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

#endif
