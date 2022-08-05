/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:47:31 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/26 21:39:49 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_alloc_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		len += j;
		if (i != size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
				j++;
			len += j;
		}
		i++;
	}
	return (len + 1);
}

void	join(int size, char **strs, char *sep, char *dest)
{
	int	strs_idx;
	int	str_i;
	int	sep_i;
	int	dest_i;

	strs_idx = 0;
	dest_i = 0;
	while (strs_idx < size)
	{
		str_i = 0;
		while (strs[strs_idx][str_i] != '\0')
			dest[dest_i++] = strs[strs_idx][str_i++];
		if (strs_idx != size - 1)
		{
			sep_i = 0;
			while (sep[sep_i] != '\0')
				dest[dest_i++] = sep[sep_i++];
		}
		strs_idx++;
	}
	dest[dest_i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		alloc_size;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	alloc_size = count_alloc_size(size, strs, sep);
	result = (char *)malloc(sizeof(char) * alloc_size);
	if (result == NULL)
		return (NULL);
	join(size, strs, sep, result);
	return (result);
}
