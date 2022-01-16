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

int	search_table(struct s_search *param, int k)
{
	int		i;
	char	*cases;

	if (k == param->n)
	{
		if (check_table(param))
			param->complete = 1;
		return (param->complete);
	}
	cases = param->cases;
	while (cases[param->n])
	{
		if (param->cond[WAY_UP * param->n + k] == cases[param->n])
		{
			i = -1;
			while (++i < param->n)
				param->table[k + param->n * i] = cases[i];
			search_table(param, k + 1);
			if (param->complete)
				break ;
		}
		cases += param->n + 1;
	}
	return (param->complete);
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
			if (!check_table_way(param, way, i))
				return (0);
			i++;
		}
		way++;
	}
	return (1);
}

int	check_table_way(struct s_search *param, int way, int i)
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
		next_step(way, &pos);
		next_step(way, &next);
		j++;
	}
	value = count_visible(param, way, i);
	if (param->cond[way * param->n + i] != value)
		return (0);
	return (1);
}

int	count_visible(struct s_search *param, int way, int i)
{
	int				j;
	struct s_point	pos;
	int				latest_max;
	int				visible_count;
	int				value;

	j = 0;
	latest_max = 0;
	visible_count = 0;
	initialize_position(way, &pos, param->n, i);
	while (j < param->n)
	{
		value = param->table[pos.x + param->n * pos.y];
		if (latest_max < value)
		{
			latest_max = value;
			visible_count++;
		}
		next_step(way, &pos);
		j++;
	}
	return (visible_count);
}
