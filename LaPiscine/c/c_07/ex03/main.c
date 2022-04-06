#include <stdlib.h>
#include <stdio.h>
extern char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int size = 4;
	char *strs[] = {"abc", "abcde", "test"};
	char *sep = "AB";

	char *result = ft_strjoin(size, strs, sep);
	printf("%s\n", result);
	free(result);
}
