#include <string.h>
#include <stdio.h>
extern int	ft_strcmp(char *s1, char *s2);
int	main(void)
{
	char *str1 = "asdff";
	char *str2 = "asdfF";

	int	n1 = strcmp(str1, str2);
	int n2 = ft_strcmp(str1, str2);
	printf("%d\n", n1);
	printf("%d\n", n2);
}
