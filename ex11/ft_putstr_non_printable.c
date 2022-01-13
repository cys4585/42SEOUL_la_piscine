/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:08:19 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/13 10:06:24 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	char	*hex_arr;

	i = 0;
	hex_arr = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 127)
			ft_putchar(str[i]);
		else
			print_hex((unsigned char)str[i], hex_arr);
		i++;
	}
}
