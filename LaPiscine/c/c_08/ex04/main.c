#include <stdlib.h>
#include <stdio.h>

#include "ft_stock_str.h"

extern t_stock_str	*ft_strs_to_tab(int ac, char **av);
extern void	ft_show_tab(struct s_stock_str *par);

int	main(int argc, char **argv)
{
	struct s_stock_str *result = ft_strs_to_tab(argc, argv);
	if (result == NULL)
		return (0);
	printf("==================\n");
	printf("main()\n");
	printf("result->%p\n", result);
	int	 i = 0;
	while (result[i].str)
	{
		printf("원본:%p | %s\n", argv[i], argv[i]);
		printf("구조:%p | %s | %p | %s | %d\n", result[i].str, result[i].str, result[i].copy, result[i].copy, result[i].size);
		i++;
	}
	printf("=====================\n");
	ft_show_tab(result);
}
