/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:57:15 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 13:57:15 by jkong            ###   ########.fr       */
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
	char	c;
	char	*cond;

	n = argc - 1;
	if (n % 4 != 0)
		return (0);
	n = n / 4;
	if (n == 0 || n > 9)
		return (0);
	cond = malloc(4 * n);
	*cond_ptr = cond;
	i = 1;
	while (i < argc)
	{
		c = single_ascii_to_char(argv[i]);
		if (c == 0)
			return (0);
		cond[i - 1] = c;
		i++;
	}
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

char	single_ascii_to_char(char *str)
{
	if (str[0] == '\0' || str[1] != '\0')
		return (0);
	if (*str < '0' || *str > '9')
		return (0);
	return (*str - '0');
}
