/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:05:08 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/09 21:07:43 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include <stdlib.h>

void	get_arr(t_stack head, int *arr, int length)
{
	t_node	*cur;
	int		index;

	cur = head.ptr;
	index = 0;
	while (index < length)
	{
		arr[index] = cur->data;
		index++;
		cur = cur->next;
	}
}

int	get_pivots(t_stack stack[2], int pivot[2])
{
	int	length;
	int	*arr;
	int	*arr_tmp;

	length = stack[HEAD].size;
	arr = malloc(sizeof(int) * length);
	if (arr == NULL)
		return (0);
	get_arr(stack[HEAD], arr, length);
	arr_tmp = malloc(sizeof(int) * length);
	if (arr_tmp == NULL)
		return (0);
	ft_merge_sort(arr, arr_tmp, length);
	free(arr_tmp);
	pivot[ST_B] = arr[length / 3];
	pivot[ST_A] = arr[length * 2 / 3];
	free(arr);
	return (1);
}
