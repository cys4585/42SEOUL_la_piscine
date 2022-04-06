/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:28:22 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/08 19:00:46 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_2_digits(int n)
{
	if (n >= 100 || n < 0)
	{
		return ;
	}
	if (n >= 10)
	{
		print_char(n / 10 + '0');
		print_char(n % 10 + '0');
	}
	else
	{
		print_char('0');
		print_char(n + '0');
	}
}

void	print_between(int min, int max)
{
	int	cur;

	cur = min + 1;
	if (min == 98)
	{
		print_2_digits(min);
		print_char(' ');
		print_2_digits(cur);
	}
	else
	{
		while (cur <= max)
		{
			print_2_digits(min);
			print_char(' ');
			print_2_digits(cur);
			print_char(',');
			print_char(' ');
			cur++;
		}
	}
}

void	ft_print_comb2(void)
{
	int	min;
	int	max;

	min = 0;
	max = 99;
	while (min < max)
	{
		print_between(min, max);
		min++;
	}
}
