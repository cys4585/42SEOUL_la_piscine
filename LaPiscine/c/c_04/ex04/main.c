#include <stdio.h>
extern void	ft_putnbr_base(int nbr, char *base);
int	main(void)
{
	ft_putnbr_base(0, "poneyvif");
	printf("\n");
	ft_putnbr_base(-2147483648, "01234567");
	printf("\n");
	ft_putnbr_base(2147483647, "01");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(0, "0123456789");
	printf("\n");
}
