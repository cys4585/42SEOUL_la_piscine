/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:43:04 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/23 18:24:12 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_size_of_file(char *path)
{
	int		fd;
	int		len;
	int		size;
	char	*buf[512];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	len = -2;
	while (len != 0)
	{
		len = read(fd, buf, 512);
		if (len == -1)
			return (-1);
		size += len;
	}
	return (size);
}

char	*read_dict_file(char *path)
{
	int		fd;
	int		size;
	char	*buf;

	size = check_size_of_file(path);
	if (size < 0)
		return (NULL);
	buf = (char *)malloc(size);
	if (buf == NULL)
		return (NULL);
	fd = open("./numbers.dict", O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = read(fd, buf, size);
	if (size == -1)
		return (NULL);
	close(fd);
	return (buf);
}

t_dict	*load_init_dict(void)
{
	char	*buf;
	t_dict	*head;
	int		flag;

	buf = read_dict_file("./numbers.dict");
	head = (t_dict *)malloc(sizeof(t_dict));
	if (head == NULL)
		return (NULL);
	flag = make_dict_list(&head, buf);
	free(buf);
	if (!flag)
		return (NULL);
	return (head);
}

int	load_reference_dict(char *path, t_dict *dict)
{
//	char	*buf;

//	buf = read_dictd_file(path);
//  flag = modify_add_entry(&dict, buf);
//	free(buf);
//	if (!flag)
//		return (0);
	return (1);
}
