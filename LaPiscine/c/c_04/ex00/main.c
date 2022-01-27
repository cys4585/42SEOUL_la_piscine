#include <string.h>
#include <stdio.h>
extern int	ft_strlen(char *str);
int	main(void)
{
	char *str = "asdjfhasdkjhaksdjhadsjk123123";

	int	l1 = strlen(str);
	printf("%d\n", l1);
	
	int l2 = ft_strlen(str);
	printf("%d\n", l2);
}
