/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:02:43 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:02:43 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOXES_H
# define BOXES_H

int		read_condition(char **cond_ptr, int argc, char **argv);
void	new_table(int n, char **table_ptr);
void	print_table(int n, char *table);
char	single_ascii_to_char(char *str);

#endif
