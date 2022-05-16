/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:17:09 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/16 14:41:13 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dst;
	int		i;

	len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *old_str, char const *buf)
{
	char	*new_str;
	size_t	len_old;
	size_t	len_buf;
	size_t	i;

	if (old_str == NULL && buf == NULL)
		return (NULL);
	if (old_str == NULL)
		return (ft_strdup(buf));
	if (buf == NULL)
		return (ft_strdup(old_str));
	len_old = ft_strlen(old_str);
	len_buf = ft_strlen(buf);
	new_str = (char *)malloc(sizeof(char) * (len_old + len_buf + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len_old)
		new_str[i] = old_str[i];
	i = -1;
	while (++i < len_buf)
		new_str[len_old + i] = buf[i];
	new_str[len_old + i] = '\0';
	free((void *)old_str);
	return (new_str);
}

char	*split_nl(char *str, char **backup_str_p)
{
	char	*tmp_str;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (NULL);
	tmp_str = str;
	if (str[i + 1] == '\0')
		*backup_str_p = NULL;
	else
		*backup_str_p = ft_strdup(&str[i + 1]);
	str[i + 1] = '\0';
	str = ft_strdup(str);
	free(tmp_str);
	return (str);
}

t_list	*lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node && node->next)
		node = node->next;
	return (node);
}
