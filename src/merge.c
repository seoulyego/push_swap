/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:35:49 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/10 16:01:31 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	merge(int *arr, int low, int high, int *arr_tmp)
{
	int	mid;
	int	index_left;
	int	index_right;
	int	index_tmp;

	mid = (high + low) / 2;
	index_left = low;
	index_right = mid;
	index_tmp = low;
	while (index_tmp < high)
	{
		if (index_left < mid
			&& (index_right >= high || arr[index_left] <= arr[index_right]))
		{
			arr_tmp[index_tmp] = arr[index_left];
			index_left++;
		}
		else
		{
			arr_tmp[index_tmp] = arr[index_right];
			index_right++;
		}
		index_tmp++;
	}
}

void	split_merge(int *arr_tmp, int low, int high, int *arr)
{
	int	mid;

	if (high - low <= 1)
		return ;
	mid = (high + low) / 2;
	split_merge(arr, low, mid, arr_tmp);
	split_merge(arr, mid, high, arr_tmp);
	merge(arr_tmp, low, high, arr);
}

void	copy_array(int *arr, int low, int high, int *arr_tmp)
{
	int	index;

	index = low;
	while (index < high)
	{
		arr_tmp[index] = arr[index];
		index++;
	}
}

void	ft_merge_sort(int *arr, int *arr_tmp, int length)
{
	copy_array(arr, 0, length, arr_tmp);
	split_merge(arr_tmp, 0, length, arr);
}
