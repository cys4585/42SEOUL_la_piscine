/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:37:29 by jkong             #+#    #+#             */
/*   Updated: 2022/01/24 14:01:00 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <unistd.h>

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	digit;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		digit = *str++ - '0';
		number = 10 * number + sign * digit;
	}
	return (number);
}

// 매개변수를 (void *)로 받고, (char *)변수를 만들어서 사용한 이유가 궁금합니다.
// dest를 왜 반환하는지도 궁금합니다.
void	*ft_memcpy(void *dest, void *src, int n)
{
	char	*dest_byte_buf;
	char	*src_byte_buf;
	int		i;

	dest_byte_buf = dest;
	src_byte_buf = src;
	i = 0;
	while (i < n)
	{
		dest_byte_buf[i] = src_byte_buf[i];
		i++;
	}
	return (dest);
}

void	ft_write_string(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(STDOUT_FILENO, str, len);
}
