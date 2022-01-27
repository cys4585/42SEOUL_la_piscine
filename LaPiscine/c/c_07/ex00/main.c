extern char	*ft_strdup(char *src);
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *str = ft_strdup("Hello World!");
	printf("%s\n", str);
	printf("%p\n", str);
	free(str);
	str = ft_strdup("Hi~~");
	printf("%s\n", str);
	printf("%p\n", str);
	free(str);
}
