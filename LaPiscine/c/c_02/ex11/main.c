#include <stdio.h>
extern void	ft_putstr_non_printable(char *str);
int	main(void)
{
	char str[100] = "Coucou\ntu vas bien ?";
	str[0] = -106;
	str[1] = 44;
	str[2] = 127;
	ft_putstr_non_printable(str);
}
