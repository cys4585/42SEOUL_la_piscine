#include <stdio.h>

extern char *ft_convert_base(char *nbr, char *base_from, char *base_to);
// 0 출력 error
int main(void)
{
	char *result = ft_convert_base("  \n\v\f\r +--++--+-0abc", "0123", "poneyvif");
	printf("%s\n", result);
}
