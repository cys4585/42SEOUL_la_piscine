/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:26 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/17 19:12:48 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rec(unsigned int n, int fd)
{
	if (n > 0)
	{
		rec(n / 10, fd);
		write(fd, &"0123456789"[n % 10], 1);
	}
}

void	ft_put_u_nbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == 0)
		write(fd, "0", 1);
	else
		rec(n, fd);
}

int	get_num_len(int num)
{
	int	cnt;

	if (num == 0)
		return (1);
	cnt = 0;
	if (num < 0)
		cnt++;
	while (num)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

int	get_u_num_len(unsigned int num)
{
	int	cnt;

	if (num == 0)
		return (1);
	cnt = 0;
	while (num)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

int	handle_diu(va_list ap, char fs)
{
	int				len;
	int				num;
	unsigned int	u_num;

	if (fs == 'd' || fs == 'i')
	{
		num = va_arg(ap, int);
		ft_putnbr_fd(num, STDOUT_FILENO);
		len = get_num_len(num);
	}
	else
	{
		u_num = va_arg(ap, unsigned int);
		ft_put_u_nbr_fd(u_num, STDOUT_FILENO);
		len = get_u_num_len(u_num);
	}
	return (len);
}
