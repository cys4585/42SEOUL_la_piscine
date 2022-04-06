#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	printf("%d %d %d\n", ABS(1), ABS(0), ABS(-2));
	printf("%d %d %ld\n", ABS(15), ABS(30), ABS(-2147483648));
}
