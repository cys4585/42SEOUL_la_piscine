/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:37:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/23 17:49:20 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

char	*find(t_dict *dict, int key)
{
	if (dict == NULL)
		return (NULL);
	if (dict->key == key)
		return (dict->value);
	return (find(dict->next, key));
}

void	find_values(char ***str_arr_p, t_dict *dict, int nbr, int power)
{
	char	**tmp_arr;

	if (nbr == 0)
		return ;
	tmp_arr = *str_arr_p;
	if (nbr / 100 > 0)
	{
		tmp_arr[0] = find(dict, nbr / 100);
		tmp_arr[1] = find(dict, 100);
	}
	nbr = nbr % 100;
	if (0 < nbr)
	{
		if (nbr < 20)
			tmp_arr[2] = find(dict, nbr);
		else
		{
			tmp_arr[2] = find(dict, (nbr / 10) * 10);
			if (nbr % 10 > 0)
				tmp_arr[3] = find(dict, nbr % 10);
		}
	}
	if (power != 0)
		tmp_arr[4] = find(dict, -power);
}

void	print_str_arr(char **str_arr, int size)
{
	int	i;
	int	last_idx;

	i = size - 1;
	while (0 < i)
	{
		if (str_arr[i])
		{
			last_idx = i;
			break ;
		}
		i--;
	}
	i = 0;
	while (i < size)
	{
		if (i == last_idx)
			printf("%s", str_arr[i]);
		else if (str_arr[i])
			printf("%s ", str_arr[i]);
		i++;
	}
	printf("\n");
}

char	**resolve(t_dict *dict, int **arr_p, int arr_size)
{
	int		i;
	char	**str_arr;
	char	**tmp_arr;
	int		*arr;

	arr = *arr_p;
	str_arr = (char **)malloc(sizeof(char *) * 5 * arr_size);
	if (str_arr == NULL)
		return (NULL);
	if (arr_size == 1 && arr[0] == 0)
		str_arr[0] = find(dict, 0);
	else
	{
		tmp_arr = str_arr;
		i = 0;
		while (i < arr_size)
		{
			find_values(&tmp_arr, dict, arr[i], 3 * (arr_size - i - 1));
			tmp_arr += 5;
			i++;
		}
	}
	print_str_arr(str_arr, 5 * arr_size);
	return (str_arr);
}
