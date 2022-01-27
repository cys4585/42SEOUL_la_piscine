/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:16:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/12 16:37:55 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	di;
	int	si;

	di = 0;
	si = 0;
	while (dest[di] != '\0')
		di++;
	while (src[si] != '\0')
	{
		dest[di] = src[si];
		di++;
		si++;
	}
	dest[di] = '\0';
	return (dest);
}
