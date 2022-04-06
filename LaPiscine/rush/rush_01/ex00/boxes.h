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
int		calculate_length(char *str);
void	new_table(int n, char **table_ptr);
void	print_table(int n, char *table);

#endif
