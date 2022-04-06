/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:28:48 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/11 17:00:41 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet_or_numeric(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (str[i] != '\0')
	{
		if (is_alphabet_or_numeric(str[i]))
		{
			if (first && ('a' <= str[i] && str[i] <= 'z'))
			{
				str[i] = str[i] - 32;
			}
			else if (!first && ('A' <= str[i] && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			first = 0;
		}
		else
			first = 1;
		i++;
	}
	return (str);
}
