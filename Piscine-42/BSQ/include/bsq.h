/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:06:35 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:38:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_air
{
	int		x;
	int		y;
	int		c;
	int		max;
}				t_air;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_cmp(char s, char *charset);
char			*ft_strcat(char *dest, char src);
int				ft_size(char *str, char *charset, int i);
char			**ft_split(char *str, char *charset);
char			*stread(char *map);
char			**ft_mapparser(char *len);
int				**create(char **lines);
int				ft_size2(char **lines);
int				ft_check(char **lines, int x, int y, int c);
t_air			*ft_square(char **lines);
char			**ft_change(char **lines, t_air *tab);
int				error(char **lines, int argc);

#endif
