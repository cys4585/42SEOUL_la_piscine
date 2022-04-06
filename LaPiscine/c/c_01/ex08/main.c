/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:35:15 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 16:29:59 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int size = 10;
	int tab[10] = {9, 10, 2, -4, 0, -123, 50, 90, -10, 0};
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	ft_sort_int_tab(tab, size);
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
}
