/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:15:01 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/18 19:20:53 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ui_nbr_fd(unsigned int nbr, char *nbr_arr, int base, int fd)
{
	if (fd < 0)
		return ;
	if (nbr > 0)
	{
		put_ui_nbr_fd(nbr / base, nbr_arr, base, fd);
		write(fd, &(nbr_arr[nbr % base]), 1);
	}
}

int	get_ui_nbr_len(unsigned int nbr, int base)
{
	int	cnt;

	if (nbr == 0)
		return (1);
	cnt = 0;
	while (nbr)
	{
		nbr /= base;
		cnt++;
	}
	return (cnt);
}

int	handle_uxx(va_list ap, char fs)
{
	unsigned int	nbr;
	int				base;
	char			*nbr_arr;

	if (fs == 'u')
	{
		base = 10;
		nbr_arr = "0123456789";
	}
	else
	{
		base = 16;
		if (fs == 'x')
			nbr_arr = "0123456789abcdef";
		else
			nbr_arr = "0123456789ABCDEF";
	}
	nbr = va_arg(ap, unsigned int);
	if (nbr == 0)
		write(STDOUT_FILENO, "0", 1);
	else
		put_ui_nbr_fd(nbr, nbr_arr, base, STDOUT_FILENO);
	return (get_ui_nbr_len(nbr, base));
}