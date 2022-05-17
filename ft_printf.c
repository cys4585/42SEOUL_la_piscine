/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:35:38 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/17 19:18:59 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(va_list ap, char fs)
{
	int		len;
	void	*p;

	if (ft_strchr("cs%", fs))
		return (handle_cs5(ap, fs));
	if (ft_strchr("diu", fs))
		return (handle_diu(ap, fs));
	else if (fs == 'p')
		p = va_arg(ap, void *);
	else if (fs == 'x')
		va_arg(ap, unsigned int);
	else if (fs == 'X')
		va_arg(ap, unsigned int);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;
	char	fs;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			fs = *(++format);
			if (ft_strchr("cspdiuxX%", fs))
				cnt += handle_format_specifier(ap, fs);
		}
		else
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			cnt++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
