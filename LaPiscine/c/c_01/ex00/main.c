/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:34:34 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/09 19:00:11 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	n;
	int	*nbr;

	n = 0;
	nbr = &n;
	printf("%p", nbr);
	printf("%p", &n);
	printf("\n");
	printf("%d", *nbr);
	printf("%d", n);
	printf("\n");
	ft_ft(nbr);
	printf("%p", nbr);
	printf("%p", &n);
	printf("\n");
	printf("%d", *nbr);
	printf("%d", n);
}
