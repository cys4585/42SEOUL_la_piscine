#include <string.h>
#include <stdio.h>
extern int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char *s1 = "HelloWorldii";
	char *s2 = "HelluWorldia";
	int	n1 = strncmp(s1, s2, 20);
	int n2 = ft_strncmp(s1, s2, 20);
	printf("%d\n", n1);
	printf("%d\n", n2);
}
