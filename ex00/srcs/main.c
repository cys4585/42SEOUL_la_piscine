/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:55:27 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 21:13:20 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

#define EXIT_ERROR 2
#define EXIT_DICT_ERROR 3

int	end(int exit_code, t_resolve *res, t_dict_init *init, t_dictionary *dict)
{
	t_str_chain	*chain;

	if (exit_code == EXIT_SUCCESS)
	{
		chain = res->head;
		while (chain)
		{
			if (chain != res->head)
				ft_write_string(" ");
			ft_write_string(chain->str);
			chain = chain->next;
		}
		ft_write_string("\n");
	}
	if (exit_code == EXIT_ERROR)
		ft_write_string("Error\n");
	if (exit_code == EXIT_DICT_ERROR)
		ft_write_string("Dict Error\n");
	resolve_destruct(res);
	dict_init_destruct(init);
	dictionary_destruct(dict);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_resolve		*res;
	t_dict_init		*init;
	t_dictionary	*dict;

	res = NULL;
	init = NULL;
	dict = NULL;
	res = resolve_construct();
	if (res == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!resolve_init(res, argc, argv))
		return (end(EXIT_ERROR, res, init, dict));
	init = dict_init_construct();
	if (init == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!dict_init_load(init, res->reference_path))
		return (end(EXIT_DICT_ERROR, res, init, dict));
	dict = dictionary_construct();
	if (dict == NULL)
		return (end(EXIT_FAILURE, res, init, dict));
	if (!dictionary_apply_init(dict, init))
		return (end(EXIT_DICT_ERROR, res, init, dict));
	if (!resolve_try_doing(res, dict))
		return (end(EXIT_DICT_ERROR, res, init, dict));
	return (end(EXIT_SUCCESS, res, init, dict));
}
