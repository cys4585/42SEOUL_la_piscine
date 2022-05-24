/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:13:48 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/19 16:29:38 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_cs5(va_list ap, char fs)
{
	int				len;
	char			*str;

	len = 1;
	if (fs == '%')
		ft_putchar_fd(fs, STDOUT_FILENO);
	else if (fs == 'c')
		ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, STDOUT_FILENO);
		len = ft_strlen(str);
	}
	return (len);
}
