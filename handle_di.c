/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:26 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/18 17:18:28 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_nbr_len(int nbr)
{
	int	cnt;

	if (nbr == 0)
		return (1);
	cnt = 0;
	if (nbr < 0)
		cnt++;
	while (nbr)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

int	handle_di(va_list ap)
{
	int	nbr;

	nbr = va_arg(ap, int);
	ft_putnbr_fd(nbr, STDOUT_FILENO);
	return (get_nbr_len(nbr));
}
