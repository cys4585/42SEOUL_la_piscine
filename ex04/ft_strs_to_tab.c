/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:06:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/27 11:41:03 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <stdlib.h>

int	insert_str(t_stock_str *stock_str_p, char **str_p)
{
	int	i;

	i = 0;
	while ((*str_p)[i])
		i++;
	stock_str_p->size = i;
	stock_str_p->str = *str_p;
	stock_str_p->copy = (char *)malloc(sizeof(char) * (i + 1));
	if (stock_str_p->copy == NULL)
		return (0);
	i = 0;
	while ((*str_p)[i])
	{
		stock_str_p->copy[i] = (*str_p)[i];
		i++;
	}
	stock_str_p->copy[i] = '\0';
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*stock_str_arr;

	if (ac < 1)
		return (NULL);
	stock_str_arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock_str_arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!insert_str(&stock_str_arr[i], &av[i]))
		{
			j = 0;
			while (j < i)
				free(stock_str_arr[j++].copy);
			free(stock_str_arr);
			return (NULL);
		}
		i++;
	}
	stock_str_arr[i].str = 0;
	return (stock_str_arr);
}
