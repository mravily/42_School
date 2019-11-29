/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:10:22 by mravily           #+#    #+#             */
/*   Updated: 2019/11/28 17:01:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct			s_multi_fd
{
	int					id_fd;
	char				*rest;
	int					i;
	struct s_multi_fd	*next;
	struct s_multi_fd	*previous;
}						t_multi_fd;

int						get_next_line(int fd, char **line);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(char *s);
void					*ft_memcpy(void *dest, const void *src, size_t n);
t_multi_fd				*ft_lstnew(int fd);
t_multi_fd				*ft_lstadd_back(t_multi_fd *root, t_multi_fd *news);
void					ft_lstdelone(t_multi_fd *head, t_multi_fd *root);
int						check_backslash_n(char *buf, char *rest);

#endif
