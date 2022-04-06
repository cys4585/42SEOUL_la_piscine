#include <stdio.h>

extern int	ft_recursive_power(int nb, int power);

int	main(void)
{
	for (int i = -3; i < 4; i++)
		for (int j = -3; j < 4; j++)
			printf("%d^%d: %d\n", i, j, ft_recursive_power(i, j));
}
