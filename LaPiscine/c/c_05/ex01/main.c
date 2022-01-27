#include <stdio.h>

extern int	ft_recursive_factorial(int nb);

int	main(void)
{
	for (int i = -3; i < 10; i++)
		printf("%d\n", ft_recursive_factorial(i));
}
