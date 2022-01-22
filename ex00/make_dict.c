/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:33:55 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/22 15:26:36 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

t_dict	*make_dict(char *dict)
{
	int	fd;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		// 오픈 안되면 ..?
		eixt(1
		return (NULL);
	}

}
