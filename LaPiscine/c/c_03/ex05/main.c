#include <string.h>
#include <stdio.h>
extern	unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int	main(void)
{
	char src[5] = "cded";

	char dest1[11] = "abcde";
	int l = strlcat(dest1, src, 8);
	printf("%s\n", dest1);
	printf("%d\n", l);

	char dest2[11] = "abcde";
	int l2 = ft_strlcat(dest2, src, 8);
	printf("%s\n", dest2);
	printf("%d\n", l2);
}
