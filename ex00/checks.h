/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:03:49 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:03:49 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# define WAY_UP 0
# define WAY_DOWN 1
# define WAY_LEFT 2
# define WAY_RIGHT 3
# define WAY_NO 4

struct s_point
{
	int	x;
	int	y;
};

void	initialize_position(int way, struct s_point *pos, int n, int i);
void	next_step(int way, struct s_point *pos);

#endif
