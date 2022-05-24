/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:41:47 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/19 16:31:14 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	handle_cs5(va_list ap, char fs);
int	handle_di(va_list ap);
int	handle_uxx(va_list ap, char fs);
int	handle_p(va_list ap);

int	ft_printf(const char *format, ...);

#endif