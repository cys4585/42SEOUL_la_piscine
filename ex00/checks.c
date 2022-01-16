/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:03:26 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:03:26 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

void	initialize_position(int way, struct s_point *pos, int n, int i)
{
	if (way == WAY_UP)
	{
		pos->x = i;
		pos->y = 0;
	}
	else if (way == WAY_DOWN)
	{
		pos->x = i;
		pos->y = n - 1;
	}
	else if (way == WAY_LEFT)
	{
		pos->x = 0;
		pos->y = i;
	}
	else if (way == WAY_RIGHT)
	{
		pos->x = n - 1;
		pos->y = i;
	}
}

void	next_step(int way, struct s_point *pos)
{
	if (way == WAY_UP)
		pos->y++;
	else if (way == WAY_DOWN)
		pos->y--;
	else if (way == WAY_LEFT)
		pos->x++;
	else if (way == WAY_RIGHT)
		pos->x--;
}
