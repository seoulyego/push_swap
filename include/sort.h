/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:39:57 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 21:38:49 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "struct.h"

typedef void (*t_rotate)(t_stack stacks[2][2]);

enum e_pivot {
	PV_B,
	PV_A
};

enum e_limit
{
	MIN,
	MAX
};

enum e_rotate
{
	CNT_A,
	CNT_B
};

// pre_sort.c
int		pre_sort(t_stack stacks[2][2], int pivot[2], int limit[2]);
// sort_util.c
int		is_sorted_stack(t_stack stacks[2][2]);
int		locate_limit(t_stack stacks[2][2], int limit[2], int std);
int		locate_insert_point(t_stack stacks[2][2], int data_ref);
// sort_condition.c
int		change_rot_count(int rot[2], int rot_tmp[2]);
void	optimize_opposite_direction(size_t size_a, size_t size_b, int rot[2]);
// sort_init.c
int		set_rot_count(t_stack stacks[2][2], int limit[2], int data_ref);
void	init_f_table(t_rotate f_rotate[3][3]);
void	set_state(int state[2], int rot[2]);
// sort_basic.c
void	get_min_rot_count(t_stack stacks[2][2], int limit[2], int rot[2]);
void	match_insert_position(t_stack stacks[2][2], int limit[2], int rot[2]);
// sort.c
void	insert_element(t_stack stacks[2][2], int rot[2]);
void	push_swap(t_stack stacks[2][2], int pivot[2]);

#endif
