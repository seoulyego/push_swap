/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:46:05 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:17:55 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser_bonus.h"
#include "../include/print_bonus.h"
#include "../../libft/include/ft_split.h"
#include "../../libft/include/ft_string.h"
#include "../../libft/include/libft.h"

int	count_table_size(char **argv)
{
	int		index;
	int		count;

	index = 1;
	count = 0;
	while (argv[index])
	{
		count += ft_res_size(argv[index], ' ');
		index++;
	}
	return (count);
}

static int	find_non_digit_char(char *str)
{
	int	index;

	index = 1;
	while (str[index] && ft_isdigit(str[index]))
		index++;
	if (str[index] != '\0')
		return (1);
	return (0);
}

static int	find_duplicated_str(char **table, int pos)
{
	int	index;
	int	str_len;

	str_len = ft_strlen(table[pos]);
	index = 0;
	while (index < pos)
	{
		if (ft_strncmp(table[index], table[pos], str_len + 1) == 0)
			return (1);
		index++;
	}
	return (0);
}

int	check_validate_table(char **table)
{
	int	index_tab;

	index_tab = 0;
	while (table[index_tab])
	{
		if (!(ft_issign(table[index_tab][0])
			|| ft_isdigit(table[index_tab][0]))
			|| find_non_digit_char(table[index_tab]))
		{
			print_error_message();
			return (0);
		}
		if (find_duplicated_str(table, index_tab))
		{
			print_error_message();
			return (0);
		}
		index_tab++;
	}
	return (1);
}
