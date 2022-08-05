/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:02:47 by jkong             #+#    #+#             */
/*   Updated: 2022/01/16 14:02:47 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cases.h"
#include <stdlib.h>

void	make_cases(int n, char **cases_ptr)
{
	int		i;
	int		case_count;
	char	*temp_array;
	char	*temp_cases;

	case_count = factorial(n);
	temp_array = malloc(n);
	i = 0;
	while (i < n)
	{
		temp_array[i] = i + 1;
		i++;
	}
	*cases_ptr = malloc((case_count + 1) * (n + 1));
	temp_cases = *cases_ptr;
	if (case_permutation(&temp_cases, temp_array, 0, n) == case_count)
	{
		i = 0;
		while (i < n)
			temp_array[i++] = 0;
		store_found_case(temp_cases, temp_array, n);
	}
	else
		*cases_ptr = 0;
	free(temp_array);
}

int	case_permutation(char **cases_ptr, char *arr, int k, int n)
{
	int	i;
	int	count;

	if (k < n)
	{
		count = 0;
		i = k;
		while (i < n)
		{
			swap_char(&arr[k], &arr[i]);
			count += case_permutation(cases_ptr, arr, k + 1, n);
			swap_char(&arr[k], &arr[i]);
			i++;
		}
	}
	else
	{
		*cases_ptr = store_found_case(*cases_ptr, arr, n);
		count = 1;
	}
	return (count);
}

char	*store_found_case(char *cases, char *arr, int n)
{
	int	i;
	int	latest_max;
	int	visible_count;

	i = 0;
	latest_max = 0;
	visible_count = 0;
	while (i < n)
	{
		cases[i] = arr[i];
		if (latest_max < arr[i])
		{
			latest_max = arr[i];
			visible_count++;
		}
		i++;
	}
	cases[i] = visible_count;
	return (cases + (n + 1));
}

int	factorial(int n)
{
	if (n > 1)
		return (n * factorial(n - 1));
	return (1);
}

void	swap_char(char *a, char *b)
{
	char	x;

	if (a == b)
		return ;
	x = *a;
	*a = *b;
	*b = x;
}
