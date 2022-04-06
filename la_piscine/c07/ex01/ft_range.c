/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:42:22 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/20 10:08:55 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (arr);
	i = 0;
	while (i < max - min)
	{
		arr[i] = i + min;
		i++;
	}
	return (arr);
}
