/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:09:23 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/13 12:46:25 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_i;

	d_len = 0;
	s_i = 0;
	while (dest[d_len] != '\0')
		d_len++;
	while (src[s_i] != '\0' && d_len + s_i + 1 < size)
	{
		dest[d_len + s_i] = src[s_i];
		s_i++;
	}
	if (size > 0)
		dest[d_len + s_i] = '\0';
	while (src[s_i] != '\0')
		s_i++;
	if (size > d_len)
		return (d_len + s_i);
	return (size + s_i);
}
