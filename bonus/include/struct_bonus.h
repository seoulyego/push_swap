/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:02:01 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:24:55 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct s_stack {
	unsigned int	stack_size;
	t_node			*ptr;
};

struct s_node {
	int		data;
	t_node	*next;
};

enum e_stack_name {
	ST_A,
	ST_B
};

enum e_stack_ptr {
	HEAD,
	TAIL
};

#endif
