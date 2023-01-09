/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:39 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/09 21:39:01 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser_bonus.h"
#include "../include/stack_bonus.h"
#include "../include/checker_bonus.h"
#include <stddef.h>

int	main(int ac, char **av)
{
	static t_stack	stacks[2][2];
	char			**str_table;

	if (ac == 1)
		return (0);
	str_table = argv_to_str_table(av);
	if (str_table == NULL)
		return (1);
	if (!init_stack(str_table, stacks[ST_A]))
	{
		clear_stacks(stacks);
		return (1);
	}
	run_operator(stacks);
	clear_stacks(stacks);
	return (0);
}
