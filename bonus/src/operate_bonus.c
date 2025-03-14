/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:05:08 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 09:45:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operator_bonus.h"
#include "../include/print_bonus.h"
#include "../../libft/include/ft_string.h"
#include "../../libft/include/get_next_line.h"

static void	init_operator(void (*f_oper[11])())
{
	f_oper[OP_PA] = pa;
	f_oper[OP_PB] = pb;
	f_oper[OP_SA] = sa;
	f_oper[OP_SB] = sb;
	f_oper[OP_SS] = ss;
	f_oper[OP_RA] = ra;
	f_oper[OP_RB] = rb;
	f_oper[OP_RR] = rr;
	f_oper[OP_RRA] = rra;
	f_oper[OP_RRB] = rrb;
	f_oper[OP_RRR] = rrr;
}

static int	get_operator(char *str)
{
	static const char	*operators[11] = {"pa\n", "pb\n", "sa\n", "sb\n", \
				"ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int					index;

	index = 0;
	while (index < 11)
	{
		if (ft_strncmp
			(str, operators[index], ft_strlen(operators[index]) + 1) == 0)
			return (index);
		index++;
	}
	return (OP_FAIL);
}

static int	is_sorted_stack(t_stack stacks[2][2])
{
	t_node	*cur_a;

	if (!(stacks[ST_B][HEAD].size == 0 && stacks[ST_B][HEAD].ptr == NULL))
		return (0);
	cur_a = stacks[ST_A][HEAD].ptr;
	while (cur_a->next != NULL)
	{
		if (cur_a->data >= cur_a->next->data)
			return (0);
		cur_a = cur_a->next;
	}
	return (1);
}

void	run_operator(t_stack stacks[2][2])
{
	static void	(*f_oper[11])(t_stack [2][2]);
	char		*str;
	int			func_num;

	init_operator(f_oper);
	str = get_next_line(0);
	while (str != NULL)
	{
		func_num = get_operator(str);
		free(str);
		if (func_num == OP_FAIL)
		{
			print_error_message();
			return ;
		}
		f_oper[func_num](stacks);
		str = get_next_line(0);
	}
	if (is_sorted_stack(stacks))
		print_result("OK");
	else
		print_result("KO");
}
