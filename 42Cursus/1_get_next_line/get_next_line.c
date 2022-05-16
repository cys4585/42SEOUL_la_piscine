/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:22:46 by youngcho          #+#    #+#             */
/*   Updated: 2022/05/16 14:36:48 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	lstdelone(t_list **lst, t_list *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		*lst = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

char	*read_one_cycle(int fd, char **backup_str_p)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*str;
	int		i;

	*backup_str_p = NULL;
	str = NULL;
	i = 0;
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		else if (read_bytes == 0)
			return (str);
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
		if (str == NULL)
			return (NULL);
		while (str[i])
			if (str[i++] == '\n')
				return (split_nl(str, backup_str_p));
	}
}

void	lstadd_back(t_list **tail_p, int fd, char *str, char **backup_str_p)
{
	t_list	*node;
	t_list	*new;
	char	*tmp_str;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->fd = fd;
	new->str = str;
	new->backup_str = NULL;
	new->prev = NULL;
	new->next = NULL;
	if (*tail_p == NULL)
		*tail_p = new;
	else
	{
		node = *tail_p;
		node->next = new;
		new->prev = node;
	}
	tmp_str = split_nl(*backup_str_p, backup_str_p);
	if (tmp_str == NULL)
		new->backup_str = *backup_str_p;
	else
		lstadd_back(&new, fd, tmp_str, backup_str_p);
}

char	*get_str_from_lst(t_list **lst, int fd, char flag, t_list *node)
{
	char	*str;
	char	**target_ptr;

	str = NULL;
	target_ptr = NULL;
	while (node)
	{
		if (node->fd == fd && flag == 's' && node->str)
			target_ptr = &(node->str);
		else if (node->fd == fd && flag == 'b' && node->str == NULL \
		&& node->backup_str)
			target_ptr = &(node->backup_str);
		if (target_ptr)
			break ;
		node = node->next;
	}
	if (target_ptr)
	{
		str = ft_strdup(*target_ptr);
		free(*target_ptr);
		*target_ptr = NULL;
		if ((flag == 's' && node->backup_str == NULL) || flag == 'b')
			lstdelone(lst, node);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*tail;
	char			*str;
	char			*backup_str;
	char			*final_str;

	str = read_one_cycle(fd, &backup_str);
	if (str != NULL)
	{
		if (head == NULL)
			lstadd_back(&head, fd, str, &backup_str);
		else
		{
			tail = lstlast(head);
			lstadd_back(&tail, fd, str, &backup_str);
		}
	}
	backup_str = get_str_from_lst(&head, fd, 'b', head);
	str = get_str_from_lst(&head, fd, 's', head);
	final_str = ft_strjoin(backup_str, str);
	if (str)
		free(str);
	else if (backup_str && !str)
		free(backup_str);
	return (final_str);
}
