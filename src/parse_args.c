/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:27:42 by yeongo            #+#    #+#             */
/*   Updated: 2023/02/07 15:15:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/stack.h"
#include "../include/print.h"
#include "../libft/include/ft_split.h"
#include "../libft/include/ft_string.h"
#include "../libft/include/ft_memory.h"
#include "../libft/include/libft.h"

static int	save_splited_str(char **str_table, int index_table, char *str)
{
	char	**tmp_table;
	int		index_tmp;

	tmp_table = ft_split(str, ' ');
	index_tmp = 0;
	while (tmp_table[index_tmp])
	{
		str_table[index_table] = ft_strdup(tmp_table[index_tmp]);
		if (str_table[index_table] == NULL)
		{
			index_table = -1;
			break ;
		}
		index_tmp++;
		index_table++;
	}
	ft_free_char(&tmp_table);
	return (index_table);
}

static int	save_str_to_table(char **str_table, int *index_table, char **argv)
{
	int	index_args;

	*index_table = 0;
	index_args = 1;
	while (argv[index_args])
	{
		if (ft_strchr(argv[index_args], ' ') != NULL)
		{
			*index_table = save_splited_str
				(str_table, *index_table, argv[index_args]);
			if (*index_table == -1)
				return (0);
		}
		else if (argv[index_args][0] != '\0')
		{
			str_table[*index_table] = ft_strdup(argv[index_args]);
			if (str_table[*index_table] == NULL)
				return (0);
			(*index_table)++;
		}
		index_args++;
	}
	str_table[*index_table] = NULL;
	return (1);
}

char	**argv_to_str_table(char **argv)
{
	char	**str_table;
	int		table_size;
	int		index;

	table_size = count_table_size(argv);
	if (table_size < 1)
	{
		print_error_message();
		return (NULL);
	}
	str_table = ft_calloc(table_size + 1, sizeof(char *));
	if (str_table == NULL)
		return (NULL);
	index = 0;
	if (!save_str_to_table(str_table, &index, argv)
		|| !check_validate_table(str_table))
	{
		ft_free_char(&str_table);
		print_error_message();
		return (NULL);
	}
	return (str_table);
}

static int	find_duplicated_number(t_stack stack[2], char *str, int *data)
{
	t_node	*cur;

	if (!ft_atoi(str, data))
		return (1);
	cur = stack[HEAD].ptr;
	while (cur != NULL)
	{
		if (cur->data == *data)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	init_stack(char **table, t_stack stack[2])
{
	int	table_size;
	int	data;

	table_size = 0;
	while (table[table_size] != NULL)
		table_size++;
	data = 0;
	while (--table_size >= 0)
	{
		if (find_duplicated_number(stack, table[table_size], &data)
			|| !stack_push(data, stack))
		{
			ft_free_char(&table);
			print_error_message();
			return (0);
		}
	}
	ft_free_char(&table);
	return (1);
}
