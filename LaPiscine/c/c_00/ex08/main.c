/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:12:18 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/09 10:37:58 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_print_combn(int n);
extern void	ft_putchar(char c);

int	main(void)
{
	ft_print_combn(1);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(2);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(3);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_print_combn(9);
	ft_putchar('\n');
	ft_putchar('\n');
}
