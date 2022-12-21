/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:46:05 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/21 15:50:50 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../include/push_swap_bonus.h"

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

	str_len = ft_strlen(table[pos]) + 1;
	index = pos + 1;
	while (table[index])
	{
		if (ft_strncmp(table[pos], table[index], str_len) == 0)
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
		if (ft_strncmp(table[index_tab], "-", 2) == 0
			|| !(ft_issign(table[index_tab][0])
			|| ft_isdigit(table[index_tab][0]))
			|| find_non_digit_char(table[index_tab]))
		{
			put_error_message("Invalid input character\n");
			return (0);
		}
		if (find_duplicated_str(table, index_tab))
		{
			put_error_message("Duplicated number\n");
			return (0);
		}
		index_tab++;
	}
	return (1);
}
