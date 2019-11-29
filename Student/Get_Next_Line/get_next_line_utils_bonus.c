/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:28:47 by mravily           #+#    #+#             */
/*   Updated: 2019/11/27 21:11:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if ((dst == 0 && src == 0) || (dst == src))
		return (dst);
	while (n--)
		tmp1[n] = tmp2[n];
	return (dst);
}

char			*ft_strdup(char *s)
{
	size_t	i;
	size_t	len_s;
	char	*dup;

	len_s = 0;
	while (s[len_s])
		len_s++;
	if (!(dup = (char *)malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	if (!(new_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(new_s, s1, len_s1);
	ft_memcpy(new_s + len_s1, s2, len_s2);
	new_s[len_s1 + len_s2] = '\0';
	free(s1);
	s1 = NULL;
	return (new_s);
}

int				check_backslash_n(char *buf, char *rest)
{
	size_t			i;
	size_t			len_rest;

	i = 0;
	len_rest = 0;
	if (rest[0] == '\n')
		return (len_rest);
	while (rest[len_rest] != '\n' && rest[len_rest])
		len_rest++;
	while (buf[i] || rest[len_rest] == '\n')
	{
		if (buf[i] == '\n' || rest[len_rest] == '\n')
			return (len_rest);
		i++;
	}
	return (-1);
}

void			ft_lstdelone(t_multi_fd *head, t_multi_fd *root)
{
	if (!head)
		return ;
	if (head->next == NULL && head->previous != NULL)
		head->previous->next = NULL;
	else if (head->previous == NULL && head->next != NULL)
		root = head->next;
	else if (head->next != NULL && head->previous != NULL)
		head->previous->next = head->next;
	else if (head->next == NULL && head->previous == NULL)
		root = NULL;
	free(head->rest);
	free(head);
}
