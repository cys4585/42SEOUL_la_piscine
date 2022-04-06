#include <stdio.h>

extern char **ft_split(char *str, char *charset);

int main(int argc, char **argv)
{
	char **str;
	if (argc != 3)
		printf("Error\n");
	printf("str:\"%s\" || charset:\"%s\"\n", argv[1], argv[2]);
	str = ft_split(argv[1], argv[2]);
	printf("tab start\n");
	for(int i = 0; str[i]; i++)
	{
		printf("tab[%d]: %s\n", i, str[i]);
	}
	printf("tab end\n");
}
