/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:08:19 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/12 11:11:59 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	make_hex_arr(char *arr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			arr[i] = i + 48;
		else
			arr[i] = i + 87;
		i++;
	}
}

void	print_hex(int ascii_decimal, char *hex_arr)
{
	ft_putchar('\\');
	ft_putchar(hex_arr[ascii_decimal / 16]);
	ft_putchar(hex_arr[ascii_decimal % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex_arr[16];

	i = 0;
	make_hex_arr(hex_arr);
	while (str[i] != '\0')
	{
		if (0 <= str[i] && str[i] <= 31)
			print_hex(str[i], hex_arr);
		else
			ft_putchar(str[i]);
		i++;
	}
}
