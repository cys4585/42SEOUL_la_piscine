/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:47:14 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 13:51:12 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	n1;
	int	n2;

	n1 = 10;
	n2 = 3;
	printf("%d %d\n", n1, n2);
	ft_ultimate_div_mod(&n1, &n2);
	printf("%d %d\n", n1, n2);
}
