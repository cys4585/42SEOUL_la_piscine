//#include <stdio.h>
//extern int	ft_atoi_base(char *str, char *base);
//int	main(void)
//{
//	char *str = " ---+--1fQ";
//	int	n = ft_atoi_base(str, "0123456789abcdef");
//	printf("%d\n", n);
//}
#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main(int argc, char **argv) {
	if (argc < 3) {
		puts("Invalid arg");
		return -1;
	}
	printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	return 0;
}
