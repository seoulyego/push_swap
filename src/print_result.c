/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:04:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/06 00:38:01 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	print_result(char *str)
{
	ft_putendl_fd(str, 1);
}

void	print_error_message(void)
{
	ft_putendl_fd("Error", 2);
}
