/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:35:38 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/19 16:25:12 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_specifier(va_list ap, char fs)
{
	if (ft_strchr("cs%", fs))
		return (handle_cs5(ap, fs));
	if (ft_strchr("uxX", fs))
		return (handle_uxx(ap, fs));
	if (ft_strchr("di", fs))
		return (handle_di(ap));
	if (fs == 'p')
		return (handle_p(ap));
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
