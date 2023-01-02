/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:39 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:21:00 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser_bonus.h"
#include "../include/stack_bonus.h"
#include "../include/checker_bonus.h"
#include "../../libft/include/ft_memory.h"

int	main(int ac, char **av)
{
	static t_stack	stacks[2][2];
	char			**str_table;
	int				error_check;

	if (ac == 1)
		return (0);
	str_table = argv_to_str_table(av);
	if (str_table == NULL)
		return (1);
	error_check = table_to_stack(str_table, stacks[ST_A]);
	ft_free_char(str_table);
	if (error_check == 1)
	{
		clear_stacks(stacks);
		return (1);
	}
	run_operator(stacks);
	clear_stacks(stacks);
	return (0);
}
