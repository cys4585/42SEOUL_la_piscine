/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:23:58 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/25 16:15:21 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_exist(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_arr_len(char *str, char *charset)
{
	int	i;
	int	flag;
	int	cnt;
	int	exist_char;

	flag = 0;
	cnt = 0;
	i = 0;
	while (str[i])
	{
		exist_char = check_exist(str[i], charset);
		if (exist_char == 0 && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (exist_char == 1 && flag == 1)
			flag = 0;
		i++;
	}
	return (cnt);
}

int	ft_strdup(char **dest_p, char *src, int min, int max)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(char) * (max - min + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (min + i < max)
	{
		str[i] = src[min + i];
		i++;
	}
	str[i] = '\0';
	*dest_p = str;
	return (1);
}

int	str_split(char **str_arr, int arr_idx, char *str, char *charset)
{
	int		str_idx;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (check_exist(str[i], charset) == 0 && flag == 0)
		{
			flag = 1;
			str_idx = i;
		}
		else if (check_exist(str[i], charset) == 1 && flag == 1)
		{
			if (!ft_strdup(&str_arr[arr_idx++], str, str_idx, i))
				return (0);
			flag = 0;
		}
		i++;
	}
	if (flag == 1)
		if (!ft_strdup(&str_arr[arr_idx], str, str_idx, i))
			return (0);
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	int		arr_len;

	arr_len = count_arr_len(str, charset);
	str_arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (str_arr == NULL)
		return (NULL);
	str_arr[arr_len] = NULL;
	if (arr_len > 0)
		if (str_split(str_arr, 0, str, charset) == 0)
			return (NULL);
	return (str_arr);
}
