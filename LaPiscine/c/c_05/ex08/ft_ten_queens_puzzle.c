/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:00:51 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/20 16:31:55 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *map)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(map[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_valid(int *map, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (map[i] == map[idx])
			return (0);
		if (map[i] + (idx - i) == map[idx])
			return (0);
		if (map[i] - (idx - i) == map[idx])
			return (0);
		i++;
	}
	return (1);
}

void	rec_fn(int *map, int idx, int *cnt_ptr)
{
	int	val;

	if (idx == 10)
	{
		*cnt_ptr += 1;
		print(map);
		return ;
	}
	val = 0;
	while (val < 10)
	{
		map[idx] = val;
		if (is_valid(map, idx))
			rec_fn(map, idx + 1, cnt_ptr);
		val++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	map[10];
	int	cnt;

	cnt = 0;
	rec_fn(map, 0, &cnt);
	return (cnt);
}
