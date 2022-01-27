/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:09:21 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/08 20:32:04 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putnbr(int nb);
extern void	ft_putchar(char c);

int	main(void)
{
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(10);
	ft_putchar('\n');
	ft_putnbr(5);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(123523);
	ft_putchar('\n');
	ft_putnbr(89237);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-5);
	ft_putchar('\n');
	ft_putnbr(-123);
	ft_putchar('\n');
	ft_putnbr(-912781);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
}
