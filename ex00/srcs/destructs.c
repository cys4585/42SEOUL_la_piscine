/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:42:11 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 20:34:12 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

void	resolve_destruct(t_resolve *this)
{
	t_str_chain	*elem;
	t_str_chain	*next;

	if (this == NULL)
		return ;
	this->reference_path = NULL;
	this->convert_input = NULL;
	free(this->tab);
	this->tab = NULL;
	this->tab_size = 0;
	elem = this->head;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	this->tail = NULL;
	free(this);
}

void	dictionary_destruct(t_dictionary *this)
{
	t_dict_elem	*elem;
	t_dict_elem	*next;

	if (this == NULL)
		return ;
	elem = this->head;
	while (elem)
	{
		next = elem->next;
		free(elem->value);
		free(elem);
		elem = next;
	}
	this->tail = NULL;
	free(this);
}

void	dict_init_destruct(t_dict_init *this)
{
	t_str_chain	*elem;
	t_str_chain	*next;

	if (this == NULL)
		return ;
	elem = this->temp_head;
	while (elem)
	{
		free(elem->str);
		next = elem->next;
		free(elem);
		elem = next;
	}
	this->temp_tail = NULL;
	elem = this->final_head;
	while (elem)
	{
		free(elem->str);
		next = elem->next;
		free(elem);
		elem = next;
	}
	this->final_tail = NULL;
	free(this);
}
