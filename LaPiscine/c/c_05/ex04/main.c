#include <stdio.h>

extern int	ft_fibonacci(int index);

int	main(void)
{
	for (int i = -3; i < 10; i++)
		printf("fibo(%d): %d\n", i, ft_fibonacci(i));
}
