/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:02:01 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/21 15:29:52 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct s_stack	t_stack;

struct s_stack {
	int				data;
	unsigned int	stack_size;
	t_stack			*next;
};

void	pa(t_stack *head_b, t_stack *head_a);
void	pb(t_stack *head_a, t_stack *head_b);
void	sa(t_stack *head_a);
void	sb(t_stack *head_b);
void	ss(t_stack *head_a, t_stack *head_b);
t_stack	*get_last_element(t_stack *head);
void	ra(t_stack *head_a);
void	rb(t_stack *head_b);
void	rr(t_stack *head_a, t_stack *head_b);
void	rra(t_stack *head_a);
void	rrb(t_stack *head_b);
void	rrr(t_stack *head_a, t_stack *head_b);
void	put_error_message(char *str);
int		count_table_size(char **argv);
int		check_validate_table(char **table);

#endif
