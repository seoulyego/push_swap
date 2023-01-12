/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:39 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/12 17:35:58 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/stack.h"
#include "../include/init.h"
#include "../include/sort.h"
#include <stddef.h>

int	main(int ac, char **av)
{
	static t_stack	stacks[2][2];
	static int		pivot[2];
	char			**str_table;

	if (ac == 1)
		return (0);
	str_table = argv_to_str_table(av);
	if (str_table == NULL)
		return (1);
	if (!init_stack(str_table, stacks[ST_A])
		|| !get_pivots(stacks[ST_A], pivot))
	{
		clear_stacks(stacks);
		return (1);
	}
	push_swap(stacks, pivot);
	clear_stacks(stacks);
	return (0);
}
