/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:24:57 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/19 16:34:33 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ull_nbr_fd(unsigned long long nbr, char *nbr_arr, int base, int fd)
{
	if (nbr > 0)
	{
		put_ull_nbr_fd(nbr / base, nbr_arr, base, fd);
		write(fd, &(nbr_arr[nbr % base]), 1);
	}
}

int	get_ull_nbr_len(unsigned long long nbr, int base)
{
	int	cnt;

	if (nbr == 0)
		return (3);
	cnt = 2;
	while (nbr)
	{
		nbr /= base;
		cnt++;
	}
	return (cnt);
}

int	handle_p(va_list ap)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)va_arg(ap, void *);
	if (nbr == 0)
		write(STDOUT_FILENO, "0x0", 3);
	else
	{
		write(STDOUT_FILENO, "0x", 2);
		put_ull_nbr_fd(nbr, "0123456789abcdef", 16, STDOUT_FILENO);
	}
	return (get_ull_nbr_len(nbr, 16));
}
