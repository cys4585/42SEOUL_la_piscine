/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:35:38 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 13:42:01 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	div;
	int	mod;

	div = 0;
	mod = 0;
	printf("%d %d\n", div, mod);
	ft_div_mod(10, 3, &div, &mod);
	printf("%d %d\n", div, mod);
}
