/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:21:11 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/20 19:02:43 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_return_base_nbr(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		i++;
	}
	return (i);
}

char	*pass_trash_check_sign_len(char *str, int *sign, int *len, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	while (str[i + *len] != '\0')
	{
		j = 0;
		while (base[j] != '\0' && str[i + *len] != base[j])
			j++;
		if (base[j] == '\0')
			break ;
		(*len)++;
	}
	return (str + i);
}

int	convert_to_decimal(char *str, int len, char *base, int mul_nbr)
{
	int		i;
	int		j;
	int		decimal_nbr;

	decimal_nbr = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		decimal_nbr = decimal_nbr * mul_nbr + j;
		i++;
	}
	return (decimal_nbr);
}
