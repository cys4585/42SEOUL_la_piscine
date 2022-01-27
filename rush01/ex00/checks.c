/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:03:26 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:03:26 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

void	initialize_position(int way, struct s_point *pos, int n, int i)
{
	if (way == WAY_UP)
	{
		pos->x = i;
		pos->y = 0;
	}
	else if (way == WAY_DOWN)
	{
		pos->x = i;
		pos->y = n - 1;
	}
	else if (way == WAY_LEFT)
	{
		pos->x = 0;
		pos->y = i;
	}
	else if (way == WAY_RIGHT)
	{
		pos->x = n - 1;
		pos->y = i;
	}
}

void	next_step(int way, struct s_point *pos)
{
	if (way == WAY_UP)
		pos->y++;
	else if (way == WAY_DOWN)
		pos->y--;
	else if (way == WAY_LEFT)
		pos->x++;
	else if (way == WAY_RIGHT)
		pos->x--;
}

int	count_visible(char *table, int n, int way, int i)
{
	int				j;
	struct s_point	pos;
	int				latest_max;
	int				visible_count;
	int				value;

	j = 0;
	latest_max = 0;
	visible_count = 0;
	initialize_position(way, &pos, n, i);
	while (j < n)
	{
		value = table[pos.x + n * pos.y];
		if (latest_max < value)
		{
			latest_max = value;
			visible_count++;
		}
		next_step(way, &pos);
		j++;
	}
	return (visible_count);
}

void	set_vertical(char *table, int n, int x, char *case_array)
{
	int	y;

	y = 0;
	while (y < n)
	{
		if (case_array)
			table[x + n * y] = case_array[y];
		else
			table[x + n * y] = 0;
		y++;
	}
}

int	check_horizontal(char *table, int n, int x0)
{
	int	x;
	int	y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < x0)
		{
			if (table[x + n * y] == table[x0 + n * y])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
