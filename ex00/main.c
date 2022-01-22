/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:59:59 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/22 21:24:19 by youngcho         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		i;
	char	*ref_dict_path;
	int		is_valid;
	int		*arr;
	int		size;

	if (argc < 2 || argc > 3)
	{
		print("Error");
		return (0);
	}
	i = 1;
	if (argc == 3)
	{
		ref_dict_path = argv[1];
		i = 2;
	}
	is_valid = 1;
	arr = str_to_int_arr(argv[i], &is_valid, &size);
	if (!is_valid)
	{
		print("Error");
		return (0);
	}
	for (int i = 0; i < size; i++)
		printf("arr[%d]: %d\n", i, arr[i]);
	return (0);
}
