/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:46:59 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/09 16:47:02 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	print_line(int x, char f, char m, char l)
{
	int	col;

	col = 1;
	ft_putchar(f);
	if (1 == x)
	{
		ft_putchar('\n');
		return ;
	}
	while (++col < x)
		ft_putchar(m);
	ft_putchar(l);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	row = 1;
	if (x <= 0 || y <= 0)
		return ;
	print_line(x, 'A', 'B', 'C');
	if (1 == y)
		return ;
	while (++row < y)
		print_line(x, 'B', ' ', 'B');
	print_line(x, 'C', 'B', 'A');
}
