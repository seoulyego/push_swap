/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:05:08 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 13:38:14 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/print_test.h"
#include "../include/sort.h"
#include <stdlib.h>

int	merge(int *arr, int low, int high, int *arr_tmp)
{
	int	mid;
	int	index_left;
	int	index_right;
	int	index_tmp;

	mid = low + (high - low) / 2;
	index_left = low;
	index_right = mid;
	index_tmp = 0;
	while (index_tmp <= high)
	{
		if (index_left < mid \
				&& (index_right >= high || arr[index_left] <= arr[index_right]))
			arr_tmp[index_tmp++] = arr[index_left++];
		else
			arr_tmp[index_tmp++] = arr[index_right++];
	}
	while (--index_tmp >= 0)
		arr[low + index_tmp] = arr_tmp[index_tmp];
	return (1);
}

int	ft_merge_sort(int *arr, int low, int high, int *arr_tmp)
{
	int	mid;

	if (high - low < 2)
		return (1);
	mid = low + (high - low) / 2;
	ft_merge_sort(arr, low, mid, arr_tmp);
	ft_merge_sort(arr, mid, high, arr_tmp);
	if (merge(arr, low, high, arr_tmp) == 0)
		return (0);
	return (1);
}

void	get_arr(t_stack head, int *arr)
{
	t_node	*cur;
	int		index;

	index = 0;
	cur = head.ptr;
	while (cur != NULL)
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
	get_arr(stack[HEAD], arr);
	arr_tmp = malloc(sizeof(int) * length);
	if (arr_tmp == NULL)
		return (0);
	ft_merge_sort(arr, 0, length, arr_tmp);
	free(arr_tmp);
	pivot[PV_B] = arr[length / 3];
	pivot[PV_A] = arr[length - 1 - length / 3];
	free(arr);
	return (1);
}
	// printf("length : %d\n", length);
	// print_arr(arr, length);
	// print_arr(arr, length);
	// printf("pivot_1 : %d pivot_2 : %d\n", pivot[0], pivot[1]);
