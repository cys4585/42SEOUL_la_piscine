#include <stdio.h>
extern int	ft_is_prime(int nb);

int	main(void)
{
	for (int i = -3; i < 300; i++)
		if(ft_is_prime(i))
			printf("%d\n", i);
}
