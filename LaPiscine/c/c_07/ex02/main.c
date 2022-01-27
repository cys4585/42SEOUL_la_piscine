#include <stdlib.h>
#include <stdio.h>

extern int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int min = 0;
	int max = 10;
	int *arr;

	int	len = ft_ultimate_range(&arr, min, max);
	if (arr == NULL)
	{
		printf("NULL\n");
		printf("%p\n", arr);
		return (0);
	}
	for (int i = 0; i < max - min; i++)
		printf("arr[%d]: %d\n", i, arr[i]);
	printf("length: %d\n", len);
	printf("%p\n", arr);
	free(arr);
	printf("%p\n", arr);
	arr = NULL;
	printf("%p\n", arr);
	return (0);
}
