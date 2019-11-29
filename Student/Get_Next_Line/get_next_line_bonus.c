/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:25 by mravily           #+#    #+#             */
/*   Updated: 2019/11/29 12:20:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_multi_fd			*ft_lstnew(int fd)
{
	t_multi_fd	*new;

	if (!(new = (t_multi_fd *)malloc(sizeof(t_multi_fd))))
		return (NULL);
	new->id_fd = fd;
	new->rest = NULL;
	new->i = 0;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_multi_fd			*ft_lstadd_back(t_multi_fd *root, t_multi_fd *new)
{
	t_multi_fd	*tmp;

	if (!root || !new)
		return (NULL);
	tmp = root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
	return (new);
}

int					ft_cpy_lastline(int ret, char **line, t_multi_fd *head,
	t_multi_fd *root)
{
	char	*tmp;

	if (ret == 0 && head->i != -1)
	{
		head->rest[head->i] = '\0';
		*line = ft_strdup(head->rest);
		tmp = ft_strdup(head->rest + (head->i + 1));
		free(head->rest);
		head->rest = tmp;
		free(head->rest);
		return (1);
	}
	else
	{
		*line = ft_strdup(head->rest);
		free(head->rest);
		head->rest = NULL;
		return (0);
	}
}

int					ft_read_file(t_multi_fd *head, char **line,
	t_multi_fd *root)
{
	char					buf[BUFFER_SIZE + 1];
	int						ret;
	char					*tmp;

	while ((ret = read(head->id_fd, buf, BUFFER_SIZE)) > 0 || head->i != -1)
	{
		buf[ret] = '\0';
		head->rest = ft_strjoin(head->rest, buf);
		head->i = check_backslash_n(buf, head->rest);
		if (head->i >= 0)
		{
			head->rest[head->i] = '\0';
			*line = ft_strdup(head->rest);
			tmp = ft_strdup(head->rest + (head->i + 1));
			free(head->rest);
			head->rest = tmp;
			return (1);
		}
	}
	return (ft_cpy_lastline(ret, line, head, root) == 1 ? 1 : 0);
}

int					get_next_line(int fd, char **line)
{
	static t_multi_fd		*root = NULL;
	t_multi_fd				*head;
	char					buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (root)
	{
		head = root;
		while (head->next != NULL)
		{
			if (head->id_fd == fd)
				break ;
			head = head->next;
		}
		if (head->id_fd != fd)
			head = ft_lstadd_back(root, ft_lstnew(fd));
	}
	else
	{
		root = ft_lstnew(fd);
		head = root;
	}
	return (ft_read_file(head, line, root) == 1 ? 1 : 0);
}
