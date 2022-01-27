/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:33:49 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/26 11:40:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_stock_str.h"

extern t_stock_str	*ft_strs_to_tab(int ac, char **av);
extern void	ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	struct s_stock_str *result = ft_strs_to_tab(argc, argv);
	int	 i = 0;
	while (result[i].str)
	{
		printf("원본:%p | %s\n", argv[i + 1], argv[i + 1]);
		printf("구조:%p | %s | %p | %s | %d\n", result[i].str, result[i].str, result[i].copy, result[i].copy, result[i].size);
		i++;
	}
	printf("%s\n", result[i].str);
	printf("============================\n");
	ft_show_tab(result);
}
