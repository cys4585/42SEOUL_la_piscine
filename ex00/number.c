/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:08:28 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/22 21:24:35 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	validation(char *str)
{
	int	i;

	if (str[0] == '0' && str[1] != '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (i);
}
void	insert_nbr(int *arr, int i, char **str, int len)
{
	int		j;
	char	tmp[4];
	int		nbr;

	j = 0;
	while (j < 3)
	{
		if (i == 0 && len % 3 && j < 3 - (len % 3))
		{
			tmp[j] = '0';
		}
		else
		{
			tmp[j] = **str;
			(*str)++;
		}
		j++;
	}
	tmp[j] = '\0';
	j = 0;
	nbr = 0;
	while (tmp[j])
	{
		nbr = nbr * 10 + (tmp[j] - '0');
		j++;
	}
	arr[i] = nbr;
}

int	*str_to_int_arr(char *str, int *is_valid, int *size)
{
	int	str_len;
	int	*arr;
	int	s;
	int	i;

	*is_valid = validation(str);
	if (*is_valid == 0)
		return (0);
	str_len = *is_valid;
	*size = (str_len + 2) / 3;
	arr = (int *)malloc(sizeof(int) * *size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < *size)
		insert_nbr(arr, i++, &str, str_len);
	return (arr);
}
