/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:17:14 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 06:29:07 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

int	init_stack(char **table, t_stack stack[2]);
int	get_pivots(t_stack stack[2], int pivot[2]);

#endif
