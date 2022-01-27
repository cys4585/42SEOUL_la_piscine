/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:53:58 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/09 10:55:07 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recursion(int n, int digit, int cur_nbr, int *nbrs)
{
	int	i;

	if (digit == 0)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(nbrs[i] + '0');
			i++;
		}
		if (nbrs[0] != 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	while (cur_nbr <= 10 - digit)
	{
		nbrs[n - digit] = cur_nbr++;
		ft_recursion(n, digit - 1, cur_nbr, nbrs);
	}
}

void	ft_print_combn(int n)
{
	int	nbrs[10];

	ft_recursion(n, n, 0, nbrs);
}
