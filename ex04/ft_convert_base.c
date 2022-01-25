/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:08:03 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/25 16:31:51 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	is_valid_return_base_nbr(char *base);
extern char	*pass_trash_check_sign_len(char *str,
				int *sign, int *len, char *base);
extern int	convert_to_decimal(char *str, int len, char *base, int mul_nbr);

int	str_malloc(char **str_p, int nbr, int base_t, int sign)
{
	int		i;
	int		size;
	char	*tmp_str;

	i = 1;
	while (nbr >= base_t)
	{
		nbr /= base_t;
		i++;
	}
	if (sign == 1)
		size = 1 + i--;
	else
		size = 2 + i;
	tmp_str = (char *)malloc(sizeof(char) * size);
	if (tmp_str == NULL)
		return (-1);
	tmp_str[size - 1] = '\0';
	*str_p = tmp_str;
	return (i);
}

char	*convert_to_base(int nbr, char *base_to, int base_t, int sign)
{
	char	*base_nbr;
	int		i;

	i = str_malloc(&base_nbr, nbr, base_t, sign);
	if (i == -1)
		return (NULL);
	if (nbr == 0)
		base_nbr[0] = base_to[0];
	else if (sign == -1)
		base_nbr[0] = '-';
	while (nbr != 0)
	{
		base_nbr[i] = base_to[nbr % base_t];
		nbr /= base_t;
		i--;
	}
	return (base_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	base_f;
	int	base_t;
	int	sign;
	int	len;
	int	decimal_nbr;

	base_f = is_valid_return_base_nbr(base_from);
	base_t = is_valid_return_base_nbr(base_to);
	if (base_f == 0 || base_t == 0)
		return (NULL);
	sign = 1;
	len = 0;
	nbr = pass_trash_check_sign_len(nbr, &sign, &len, base_from);
	decimal_nbr = convert_to_decimal(nbr, len, base_from, base_f);
	return (convert_to_base(decimal_nbr, base_to, base_t, sign));
}
