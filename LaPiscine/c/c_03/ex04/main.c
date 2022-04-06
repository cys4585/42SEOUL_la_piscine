#include <string.h>
#include <stdio.h>
extern char	*ft_strstr(char *str, char *to_find);
int	main(void)
{
	char s1[100] = "A Garden Diary A Garden Diary A Garden Diary";
	char s2[4] = "";
	char *ptr1 = strstr(s1, s2);
	char *ptr2 = ft_strstr(s1, s2);

	printf("%s\n", ptr1);

	printf("%s\n", ptr2);
	return (0);
}
