/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:53:58 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/08 21:16:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursion(int digit, int num)
{
	if (digit == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
		return ;
	}
	while (num <= 10 - digit)
	{
		ft_putchar(num + '0');
		ft_recursion(digit - 1, ++num);
	}
}

void	ft_print_combn(int n)
{
	ft_recursion(n, 0);
}
