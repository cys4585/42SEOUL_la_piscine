#include <stdio.h>
#include <stdlib.h>

extern int	*ft_range(int min, int max);

int	main(void)
{
	int	max = 10;
	int min = 9;
	int	*arr = ft_range(min, max);
	printf("%p\n", arr);
	for (int i = 0; i < max - min; i++)
		printf("arr[%d]: %d\n", i, arr[i]);
	printf("%p\n", arr);
	free(arr);
	printf("%p\n", arr);
}
