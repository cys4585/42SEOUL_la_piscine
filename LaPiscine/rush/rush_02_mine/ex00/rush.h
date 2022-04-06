/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:58:30 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/23 18:22:50 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	 s_dict
{
	int				is_init_entry;
	int				key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

int		*str_to_int_arr(char *str, int *is_valid, int *size);

void	insert_key(t_dict *dict, char *buf, int end);
int		insert_val(t_dict *dict, char *buf, int end);
int		make_dict_list(t_dict **dict, char *buf);

int		check_size_of_file(char *path);
char	*read_dict_file(char *path);
t_dict	*load_init_dict(void);
int		load_reference_dict(char *path, t_dict *dict);

char	**resolve(t_dict *dict, int **arr, int arr_size);
#endif
