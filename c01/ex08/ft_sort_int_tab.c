/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:32:25 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 16:30:12 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_val;
	int	min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_val = tab[i];
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (min_val > tab[j])
			{
				min_val = tab[j];
				min_idx = j;
			}
			j++;
		}
		tab[min_idx] = tab[i];
		tab[i] = min_val;
		i++;
	}
}
