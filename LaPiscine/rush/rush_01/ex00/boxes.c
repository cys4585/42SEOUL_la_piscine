/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:57:15 by jkong             #+#    #+#             */
/*   Updated: 2022/01/17 17:33:45 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boxes.h"
#include <stdlib.h>
#include <unistd.h>

#define BASE_10 "0123456789"

int	read_condition(char **cond_ptr, int argc, char **argv)
{
	int		i;
	int		n;
	char	*str;
	char	*cond;

	if (argc != 2)
		return (0);
	str = argv[1];
	n = calculate_length(str);
	if (n == 0)
		return (0);
	cond = malloc(4 * n);
	*cond_ptr = cond;
	i = 0;
	while (i < 4 * n)
	{
		cond[i] = str[2 * i] - '0';
		if (cond[i] == 0 || cond[i] > n)
			return (0);
		i++;
	}
	return (n);
}
//  인풋 잘못되면 -> return (0)
//  인풋 정상이면 -> return (n))
int	calculate_length(char *str)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if ((n & 1) && str[n] != ' ')
			return (0);
		if (!(n & 1) && (str[n] < '0' || str[n] > '9'))
			return (0);
		n++;
	}
	if (!(n & 1))
		return (0);
	n = (n + 1) / 2;
	if (n % 4 != 0)
		return (0);
	n = n / 4;
	if (n == 0 || n > 9)
		return (0);
	return (n);
}

void	new_table(int n, char **table_ptr)
{
	int		i;
	char	*table;

	i = 0;
	table = malloc(n * n);
	while (i < n * n)
		table[i++] = 0;
	*table_ptr = table;
}

void	print_table(int n, char *table)
{
	int	x;
	int	y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			if (x != 0)
				write(1, " ", 1);
			write(1, &BASE_10[(int) table[x + n * y]], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
