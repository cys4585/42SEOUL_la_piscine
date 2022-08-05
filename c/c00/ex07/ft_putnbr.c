/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:01:39 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/08 20:50:46 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursion(int nb, int edge)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_recursion(nb / 10, 0);
	ft_putchar(nb % 10 + edge + '0');
}

void	ft_putnbr(int nb)
{
	int	edge;

	edge = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			edge = 1;
		}
		nb = nb - nb - nb - edge;
	}
	ft_recursion(nb, edge);
}
