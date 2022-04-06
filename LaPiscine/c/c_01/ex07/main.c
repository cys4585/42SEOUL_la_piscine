/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:30:24 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 14:49:18 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	arr[7] = {10, 15, 20, 25, 30, 35, 40};
	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");
	ft_rev_int_tab(arr, 7);
	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");

	int	arr2[6] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < 6; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	ft_rev_int_tab(arr2, 6);
	for (int i = 0; i < 6; i++)
		printf("%d ", arr2[i]);
	printf("\n");

}
