/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict_help_fn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:08:42 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/23 18:21:37 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	insert_key(t_dict *dict, char *buf, int end)
{
	int	i;
	int	nbr;

	i = 0;
	while (i < end)
	{
		if ((i == 0 && buf[i] != '1') || (i > 0 && buf[i] != '0'))
			break ;
		i++;
	}
	if (i >= 4 && i == end)
	{
		dict->key = -(i - 1);
		return ;
	}
	nbr = 0;
	i = 0;
	while (i < end)
	{
		if (buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t'
			|| buf[i] == '\v' || buf[i] == '\f' || buf[i] == '\r')
			break ;
		nbr = nbr * 10 + (buf[i++] - '0');
	}
	dict->key = nbr;
}

int	insert_val(t_dict *dict, char *buf, int end)
{
	int		i;
	char	*val;

	i = 0;
	while (buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t'
		|| buf[i] == '\v' || buf[i] == '\f' || buf[i] == '\r')
		i++;
	buf += i;
	val = (char *)malloc(end - i + 1);
	if (val == NULL)
		return (0);
	i = 0;
	while (buf[i] != '\n')
	{
		val[i] = buf[i];
		i++;
	}
	val[i] = '\0';
	dict->value = val;
	return (1);
}

int	make_dict_list(t_dict **head_p, char *buf)
{
	int		i;
	t_dict	*dict;

	dict = *head_p;
	while (*buf != '\0')
	{
		i = 0;
		while (buf[i] != ':')
			i++;
		insert_key(dict, buf, i);
		buf += (i + 1);
		i = 0;
		while (buf[i] != '\n')
			i++;
		if (!insert_val(dict, buf, i))
			return (0);
		buf += (i + 1);
		dict->next = (t_dict *)malloc(sizeof(t_dict));
		if (dict->next == NULL)
			return (0);
		dict = dict->next;
	}
	return (1);
}
