#include <stdio.h>
extern int	ft_atoi(char *str);
int	main(void)
{
	int	n = ft_atoi("\n\t\v\f\r  ---+--+1234ab567");
	printf("%d\n", n);
}
