/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:17:14 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 06:46:13 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "struct_bonus.h"

int		table_to_stack(char **table, t_stack stack[2]);
void	run_operator(t_stack stacks[2][2]);

#endif
