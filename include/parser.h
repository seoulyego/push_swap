/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:23:58 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/03 05:15:29 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		count_table_size(char **argv);
int		check_validate_table(char **table);
char	**argv_to_str_table(char **argv);

#endif
