/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:27:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/21 15:52:04 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../include/push_swap_bonus.h"

static int	save_splited_str(char **str_table, int index_table, char *str)
{
	char	**tmp_table;
	int		index_tmp;

	tmp_table = ft_split(str, ' ');
	index_tmp = 0;
	while (tmp_table[index_tmp])
	{
		str_table[index_table] = ft_strdup(tmp_table[index_tmp]);
		index_tmp++;
		index_table++;
	}
	ft_free(tmp_table, index_tmp);
	return (index_table);
}

static void	save_str_to_table(char **str_table, int *index_table, char **argv)
{
	int	index_args;

	*index_table = 0;
	index_args = 1;
	while (argv[index_args] != NULL)
	{
		if (ft_strchr(argv[index_args], ' ') != NULL)
			*index_table = save_splited_str
				(str_table, *index_table, argv[index_args]);
		else if (argv[index_args][0])
		{
			str_table[*index_table] = ft_strdup(argv[index_args]);
			(*index_table)++;
		}
		index_args++;
	}
	str_table[*index_table] = NULL;
}

char	**argv_to_str_table(char **argv)
{
	char	**str_table;
	int		table_size;
	int		index;

	table_size = count_table_size(argv);
	str_table = ft_calloc(table_size + 1, sizeof(char *));
	if (str_table == NULL)
		return (NULL);
	index = 0;
	save_str_to_table(str_table, &index, argv);
	if (!check_validate_table(str_table))
	{
		ft_free(str_table, index);
		return (NULL);
	}
	return (str_table);
}
