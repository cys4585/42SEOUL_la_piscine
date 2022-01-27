/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:47 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/19 12:02:37 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	is_bigger(char *str, char *target)
{
	int	i;

	i = 0;
	while (str[i] || target[i])
	{
		if (str[i] < target[i])
			return (0);
		else if (str[i] > target[i])
			return (1);
		i++;
	}
	return (0);
}

void	swap(char **str_ptr1, char **str_ptr2)
{
	char	*tmp;

	tmp = *str_ptr1;
	*str_ptr1 = *str_ptr2;
	*str_ptr2 = tmp;
}

char	**asc_sort(char **str_arr, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < len - 1)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (is_bigger(str_arr[min], str_arr[j]))
				min = j;
			j++;
		}
		swap(&str_arr[i], &str_arr[min]);
		i++;
	}
	return (str_arr);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		return (0);
	}
	argv = asc_sort(argv + 1, argc - 1);
	i = 0;
	while (i < argc - 1)
		ft_putstr(argv[i++]);
	return (0);
}
