/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:59 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/23 19:40:37 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		is_valid;
	int		*arr;
	int		arr_size;
	t_dict	*dict;
	char	**str_arr;

	if (argc < 2 || argc > 3)
	{
		print("error");
		return (0);
	}
	if (argc == 3)
	{
		arr = str_to_int_arr(argv[2], &is_valid, &arr_size);
		load_reference_dict(argv[1], dict);
	}
	else
		arr = str_to_int_arr(argv[1], &is_valid, &arr_size);
	if (!is_valid)
	{
		print("error");
		return (0);
	}
	dict = load_init_dict();
	if (dict == NULL)
	{
		print("Dict Error");
		return (0);
	}
	str_arr = resolve(dict, &arr, arr_size);
	
	free(arr);
	t_dict	*tmp;
	while (dict)
	{
		tmp = dict;
		free(tmp->value);
		free(tmp);
		dict = dict->next;
	}
	free(str_arr);
	//system("leaks a.out");
	return (0);
}
