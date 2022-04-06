/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:19:19 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/26 11:46:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	rec_print_int(int nbr)
{
	if (nbr >= 10)
		rec_print_int(nbr / 10);
	ft_putchar('0' + nbr % 10);
}

void	print_int(int nbr)
{
	rec_print_int(nbr);
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		print_int(par[i].size);
		print_str(par[i].copy);
		i++;
	}
}
