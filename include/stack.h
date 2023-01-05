/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:22:09 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 03:46:51 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "struct.h"

int		stack_push(int data, t_stack stack[2]);
t_node	*get_prev_element(t_stack *head, void *data_ref);
void	clear_stacks(t_stack stacks[2][2]);

#endif
