/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:12:43 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/10 14:15:10 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int	ft_strlen(char *str);

int	main(void)
{
	int	len;

	len = ft_strlen("Hello I'm youngcho\n");
	printf("%d\n", len);
	len = ft_strlen("hello I'm youngcho");
	printf("%d\n", len);
}
