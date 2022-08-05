/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:26:33 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/13 17:21:18 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	char	*space_list;
	int		i;

	space_list = " \n\t\v\f\r";
	i = 0;
	while (space_list[i] != '\0')
		if (c == space_list[i++])
			return (1);
	return (0);
}

char	*pass_space(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (str + i);
}

char	*check_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*sign = -(*sign);
	return (str + i);
}

int	atoi(char *str, int sign)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	str = pass_space(str);
	str = check_sign(str, &sign);
	result = atoi(str, sign);
	return (result);
}
