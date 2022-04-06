/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:22:03 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/15 21:35:27 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
		if (base[i] == '+' || base[i++] == '-')
			return (1);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (1);
		i++;
	}
	return (0);
}

void	rec_fn(int nbr, int b, char *base)
{
	if (nbr >= b)
		rec_fn(nbr / b, b, base);
	ft_putchar(base[nbr % b]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (is_invalid(base))
		return ;
	while (base[i])
		i++;
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			rec_fn(2147483648 / i, i, base);
			ft_putchar(base[2147483648 % i]);
			return ;
		}
		nbr = -nbr;
	}
	rec_fn(nbr, i, base);
}
