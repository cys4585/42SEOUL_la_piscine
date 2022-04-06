#include <stdio.h>
#include <string.h>
extern char *ft_strncat(char *dest, char *src, unsigned int nb);
int	main(void)
{
	char dest1[100] = "test";
	char dest2[100] = "test";
	char *src = "origin src";
	char *dest11 = strncat(dest1, src, 10);
	char *dest22 = ft_strncat(dest2, src, 105);
	printf("%s\n", dest1);
	printf("%s\n", dest11);
	printf("%s\n", dest2);
	printf("%s\n", dest22);
}
