/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:22:07 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/20 15:11:13 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (1);
		i++;
	}
	return (0);
}

char	*check_sign_and_base_nbr(char *str, int *sign, char *base, int *mul_nbr)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*sign = -(*sign);
	j = 0;
	while (base[j])
		j++;
	*mul_nbr = j;
	return (str + i);
}

int	get_nbr_len(char *str, char *base)
{
	int	si;
	int	bi;
	int	is_nbr;

	si = 0;
	while (1)
	{
		bi = 0;
		is_nbr = 0;
		while (base[bi])
		{
			if (str[si] == base[bi])
			{
				is_nbr = 1;
				break ;
			}
			bi++;
		}
		if (!is_nbr)
			return (si);
		si++;
	}
}

int	convert_to_decimal(char *str, int len, char *base, int mul_nbr)
{
	char	cnbr;
	int		si;
	int		bi;
	int		result;

	result = 0;
	si = 0;
	while (si < len)
	{
		cnbr = str[si];
		bi = 0;
		while (cnbr != base[bi])
			bi++;
		result = result * mul_nbr + bi;
		si++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	len;
	int	mul_nbr;

	if (is_invalid(base))
		return (0);
	sign = 1;
	mul_nbr = 0;
	str = check_sign_and_base_nbr(str, &sign, base, &mul_nbr);
	len = get_nbr_len(str, base);
	result = convert_to_decimal(str, len, base, mul_nbr);
	return (result * sign);
}
