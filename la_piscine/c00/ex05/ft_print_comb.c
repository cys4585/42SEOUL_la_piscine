/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:22:21 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/08 21:18:39 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nums(char *nums)
{
	char	comma[2];

	comma[0] = ',';
	comma[1] = ' ';
	write(1, nums, 3);
	if (!(nums[0] == '7' && nums[1] == '8' && nums[2] == '9'))
	{
		write(1, comma, 2);
	}
}

void	ft_print_comb(void)
{
	char	nums[4];

	nums[0] = '0';
	while (nums[0] <= '7')
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= '8')
		{
			nums[2] = nums[1] + 1;
			while (nums[2] <= '9')
			{
				print_nums(nums);
				nums[2]++;
			}
			nums[1]++;
		}	
		nums[0]++;
	}
}
