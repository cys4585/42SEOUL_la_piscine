extern void	ft_putchar(char c);

void	rush2(int x, int y)
{
	int i;
	int j;
	char c;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1)
			{
				if (j == 0)
				{
					c = 'A';
				} else if (j == x - 1)
				{
					c = 'C';
				} else
				{
					c = 'B';
				}
			} else
			{
				if (j == 0 || j == x - 1)
				{
					c = 'B';
				} else
				{
					c = ' ';
				}
			}
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	int i;
	int j;
	char vertext_l;
	char vertext_r;
	char side;

	i = 0;
	j = 0;
	vertext_l = 'A';
	vertext_r = 'C';
	side = 'B';
	while (i < y)
	{
		if (i == 0 || i == y - 1)
		{
			while (j < x)
			{
				if (j == 0)
				{
					ft_putchar(vertext_l);
				} else if (j == x - 1)
				{
					ft_putchar(vertext_r);
				} else 
				{
					ft_putchar(side);
				}
				j++;
			}
		} else
		{
			while (j < x)
			{
				if (j == 0 || j == x - 1)
				{
					ft_putchar(side);
				} else
				{
					ft_putchar(' ');
				}
				j++;
			}
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
