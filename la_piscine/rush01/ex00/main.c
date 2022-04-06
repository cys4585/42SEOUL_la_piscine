/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:51:03 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 21:46:48 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cases.h"
#include "boxes.h"
#include "search.h"
#include <unistd.h>
#include <stdlib.h>

void	print_error(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		n;
	char	*cond;
	char	*ptr;
	char	*tab;

	cond = 0;
	n = read_condition(&cond, argc, argv);
	if (n == 0)
	{
		print_error("Error");
		free(cond);
		return (0);
	}
	make_cases(n, &ptr);
	new_table(n, &tab);
	if (try_doing_search(n, ptr, tab, cond))
		print_table(n, tab);
	else
		print_error("Error");
	free(tab);
	free(ptr);
	free(cond);
	return (0);
}
