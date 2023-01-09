/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:39:57 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/09 21:35:39 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "struct.h"

typedef void	(*t_rotate)(t_stack stacks[2][2]);

enum e_limit
{
	MIN,
	MAX
};

void	ft_merge_sort(int *arr, int *arr_tmp, int length);
int		pre_sort(t_stack stacks[2][2], int pivot[2], int limit[2]);
int		is_sorted_stack(t_stack stacks[2][2]);
int		locate_limit(t_stack stacks[2][2], int limit[2], int std);
int		locate_insert_point(t_stack stacks[2][2], int data_ref);
int		change_rot_count(int rot[2], int rot_tmp[2]);
int		set_rot_count(t_stack stacks[2][2], int limit[2], int data_ref);
void	init_f_table(t_rotate f_rotate[3][3]);
void	set_state(int state[2], int rot[2]);
void	get_min_rot_count(t_stack stacks[2][2], int limit[2], int rot[2]);
void	match_insert_position(t_stack stacks[2][2], int rot[2]);
void	line_up_elements(t_stack stacks[2][2], int limit[2]);
void	insert_elements(t_stack stacks[2][2], int limit[2], int rot[2]);
void	push_swap(t_stack stacks[2][2], int pivot[2]);

#endif
