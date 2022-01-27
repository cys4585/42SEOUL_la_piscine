#include <stdio.h>
extern void	ft_putnbr(int nb);
int	main(void)
{
	int nb = 123;
	ft_putnbr(nb);
	printf("\n");

	nb = -123;
	ft_putnbr(nb);
	printf("\n");
	nb = 1;
	ft_putnbr(nb);
	printf("\n");
	nb = -1;
	ft_putnbr(nb);
	printf("\n");
	nb = 10;
	ft_putnbr(nb);
	printf("\n");
	nb = -10;
	ft_putnbr(nb);
	printf("\n");

	nb = 0;
	ft_putnbr(nb);
	printf("\n");
	nb = 2147483647;
	ft_putnbr(nb);
	printf("\n");
	nb = -2147483648;
	ft_putnbr(nb);
	printf("\n");

}
