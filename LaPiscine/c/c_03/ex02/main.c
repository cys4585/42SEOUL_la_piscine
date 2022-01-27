#include <string.h>
#include <stdio.h>
extern char *ft_strcat(char *dest, char *src);
int	main(void)
{
	char dest1[20] = "A A A abc ";
	char dest2[20] = "A A A abc ";
	char *src = "!ab!c!";
	char *dest11 = strcat(dest1, src);
	char *dest22 = ft_strcat(dest2, src);
	printf("%s\n", dest1);
	printf("%s\n", dest11);
	printf("\n");
	printf("%s\n", dest2);
	printf("%s\n", dest22);
}
