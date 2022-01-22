/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:58:30 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/22 21:07:51 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct	 s_dict
{
	int				is_init_entry;
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

int	*str_to_int_arr(char *str, int *is_valid, int *size);

#endif
