/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:30:48 by jkong             #+#    #+#             */
/*   Updated: 2022/01/25 11:05:08 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

t_dict_elem	*dictionary_get_elem(t_dictionary *this, int key)
{
	t_dict_elem	*elem;

	elem = this->head;
	while (elem)
	{
		if (elem->key == key)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

t_dict_elem	*dictionary_put_elem(t_dictionary *this, int key, char *value)
{
	t_dict_elem	*elem;

	elem = malloc(sizeof(t_dict_elem));
	if (elem)
	{
		if (this->tail)
			this->tail->next = elem;
		else
			this->head = elem;
		this->tail = elem;
		elem->key = key;
		elem->value = value;
		elem->next = NULL;
	}
	return (elem);
}

char	*dictionary_get_value(t_dictionary *this, int key)
{
	t_dict_elem	*elem;

	elem = dictionary_get_elem(this, key);
	if (elem)
		return (elem->value);
	return (NULL);
}

char	*dictionary_put_value(t_dictionary *this, int key, char *value)
{
	t_dict_elem	*elem;
	char		*old_value;

	elem = dictionary_get_elem(this, key);
	if (elem)
	{
		old_value = elem->value;
		elem->value = value;
		return (old_value);
	}
	else
	{
		(void)dictionary_put_elem(this, key, value);
		return (NULL);
	}
}

int	dictionary_apply_init(t_dictionary *this, t_dict_init *init)
{
	t_str_chain		*chain;
	char			*key;
	char			*value;
	char			*old;

	chain = init->final_head;
	while (chain)
	{
		if (chain->str[0] != '\0')
		{
			// key, value 가져오기
			if (!parse_pair(chain->str, &key, &value))
				return (0);
			// key, value 넣기
			old = dictionary_put_value(this, calc_key(key), value);
			free(key);
			free(old);
		}
		chain = chain->next;
	}
	return (1);
}
