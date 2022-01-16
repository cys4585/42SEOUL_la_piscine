/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:05:56 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:05:56 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.h"
#include <stdlib.h>

int	try_doing_search(int n, char *cases, char *table, char *cond)
{
	struct s_search	param_obj;

	param_obj.n = n;
	param_obj.cases = cases;
	param_obj.table = table;
	param_obj.cond = cond;
	param_obj.complete = 0;
	search_table(&param_obj, 0);
	return (param_obj.complete);
}

int	search_table(struct s_search *param, int x)
{
	int		i;
	int		way;
	char	*cases;

	if (x == param->n)
	{
		if (check_table(param))
			param->complete = 1;
		return (param->complete);
	}
	cases = param->cases;
	while (cases[param->n])
	{
		if (try_doing_case(param, cases, x))
		{
			search_table(param, x + 1);
			if (param->complete)
				break ;
		}
		cases += param->n + 1;
	}
	return (param->complete);
}

int	try_doing_case(struct s_search *param, char *case_array, int x)
{
	int	value;
	int	overlapped_horizon;

	if (param->cond[WAY_UP * param->n + x] == case_array[param->n])
	{
		set_vertical(param->table, param->n, x, case_array);
		value = count_visible(param->table, param->n, WAY_DOWN, x);
		overlapped_horizon = check_horizontal(param->table, param->n, x);
		set_vertical(param->table, param->n, x, 0);
		if (!overlapped_horizon)
			return (0);
		if (param->cond[WAY_DOWN * param->n + x] != value)
			return (0);
		set_vertical(param->table, param->n, x, case_array);
		return (1);
	}
	return (0);
}

int	check_table(struct s_search *param)
{
	int	way;
	int	i;

	way = WAY_UP;
	while (way < WAY_NO)
	{
		i = 0;
		while (i < param->n)
		{
			if (!check_way(param, way, i))
				return (0);
			i++;
		}
		way++;
	}
	return (1);
}

int	check_way(struct s_search *param, int way, int i)
{
	int				j;
	struct s_point	pos;
	struct s_point	next;
	int				value;

	j = 0;
	initialize_position(way, &pos, param->n, i);
	initialize_position(way, &next, param->n, i);
	next_step(way, &next);
	while (j < param->n - 1)
	{
		value = param->table[pos.x + param->n * pos.y];
		if (value == param->table[next.x + param->n * next.y])
			return (0);
		next_step(way, &next);
		next_step(way, &pos);
		j++;
	}
	value = count_visible(param->table, param->n, way, i);
	if (param->cond[way * param->n + i] != value)
		return (0);
	return (1);
}
