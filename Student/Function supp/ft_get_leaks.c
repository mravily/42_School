/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:25 by mravily           #+#    #+#             */
/*   Updated: 2019/11/27 18:40:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

extern char *prog_name;

void ft_get_leaks(char *prog_name, char *msg)
{
	size_t i;
	char *cmd;
	char *tmp;

	i = 0;
	while (msg[i] != '\0')
		i++;
	write(1, msg, i);
	tmp = "\n";
	write(1, tmp, 1);
	tmp = ft_strdup(prog_name);
	cmd = ft_strjoin(ft_strdup("leaks "), tmp);
	free(tmp);
	tmp = ft_strdup(" | grep 'total leaked bytes'");
	cmd = ft_strjoin(cmd, tmp);
	free(tmp);
	system(cmd);
	free(cmd);
	tmp = "\n";
	write(1, tmp, 1);
}

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

static int			ft_cpy_lastline(int ret, char **line, t_multi_fd *head,
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
		ft_lstdelone(head, root);
		return (0);
	}
}

static int			ft_read_file(t_multi_fd *head, char **line,
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

	if (fd < 0 || !line)
		return (-1);
	ft_get_leaks("a.out", "Avant le if root");
	if (root)
	{
		ft_get_leaks("a.out", "Root != null");
		head = root;
		ft_get_leaks("a.out", "Apres l'assignation de head");
		while (head->next != NULL)
		{
			ft_get_leaks("a.out", "A l'interieur du while de type head->next");
			if (head->id_fd == fd)
				break ;
			ft_get_leaks("a.out", "Avant le if du id_fd");
			head = head->next;
			ft_get_leaks("a.out", "Apres le if du id_fd");
		}
		ft_get_leaks("a.out", "Apres l'assignation de head");
		if (head->id_fd != fd)
			head = ft_lstadd_back(root, ft_lstnew(fd));
		ft_get_leaks("a.out", "Apres l'assignation de head");
	}
	else
	{
		ft_get_leaks("a.out", "Root == null");
		if (!(root = (t_multi_fd *)malloc(sizeof(t_multi_fd))))
			return (ERROR);
		ft_get_leaks("a.out", "Apres le mallocage du root");
		root = ft_lstnew(fd);
		ft_get_leaks("a.out", "Apres l'ajout du maillon");
		head = root;
		ft_get_leaks("a.out", "Apres l'assignation de head");
	}
	ft_get_leaks("a.out", "Apres le if root");
	return (ft_read_file(head, line, root) == 1 ? 1 : 0);
}
