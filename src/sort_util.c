/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:13:27 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 21:39:16 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"
#include "../libft/include/ft_math.h"

int	is_sorted_stack(t_stack stacks[2][2])
{
	t_node	*cur_a;

	if (!(stacks[ST_B][HEAD].size == 0 && stacks[ST_B][HEAD].ptr == NULL))
		return (0);
	cur_a = stacks[ST_A][HEAD].ptr;
	while (cur_a->next != NULL)
	{
		if (cur_a->data >= cur_a->next->data)
			return (0);
		cur_a = cur_a->next;
	}
	return (1);
}

int	locate_limit(t_stack stacks[2][2], int limit[2], int std)
{
	t_node	*cur;
	int		locate;

	cur = stacks[ST_A][HEAD].ptr;
	locate = std;
	while (cur != NULL)
	{
		if (cur->data == limit[std])
			break ;
		cur = cur->next;
		locate++;
	}
	if (locate > (stacks[ST_A][HEAD].size + 1) / 2)
		locate -= stacks[ST_A][HEAD].size;
	return (locate);
}

int	locate_insert_point(t_stack stacks[2][2], int data_ref)
{
	t_node	*cur;
	int		locate;

	cur = stacks[ST_A][HEAD].ptr;
	if (data_ref < stacks[ST_A][HEAD].ptr->data
		&& stacks[ST_A][TAIL].ptr->data < data_ref)
		return (0);
	locate = 0;
	while (cur->next != NULL)
	{
		if (cur->data < data_ref && data_ref < cur->next->data)
			break ;
		cur = cur->next;
		locate++;
	}
	if (locate > (stacks[ST_A][HEAD].size + 1) / 2)
		locate -= stacks[ST_A][HEAD].size;
	return (locate);
}

int	change_rot_count(int rot[2], int rot_tmp[2])
{
	unsigned int	sum_rot;
	unsigned int	sum_rot_tmp;

	sum_rot = ft_abs_int(rot[CNT_A]) + ft_abs_int(rot[CNT_B]);
	sum_rot_tmp = ft_abs_int(rot_tmp[CNT_A]) + ft_abs_int(rot_tmp[CNT_B]);
	if (sum_rot > sum_rot_tmp)
		return (1);
	return (0);
}

void	optimize_opposite_direction(size_t size_a, size_t size_b, int rot[2])
{
	size_t	sum_rot;
	size_t	less_size;

	sum_rot = ft_abs_int(rot[CNT_A]) + ft_abs_int(rot[CNT_B]);
	less_size = size_a * (size_a < size_b) + size_b * (size_a > size_b);
	if (sum_rot == less_size)
		rot[size_a > size_b] += less_size;
}
