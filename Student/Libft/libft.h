/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:46:21 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 16:11:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);  
void	*ft_memmove(void *dest, const void *src, size_t n);                // A FINIR //
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);                                 // A VERIFIER //
char	*ft_strrchr(const char *s, int c);                                // A VERIFIER //
// ft_strlcpy //
size_t	ft_strlcat(char *dest, const char *src, size_t n);                // A VERIFIER //
char	*ft_strnstr(const char *baystack, const char *needle, size_t n);  // A FINIR //                  

char	*ft_strdup(const char *s);
void	*calloc(size_t count, size_t size)

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);


char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *baystack, const char *needle);
char	*ft_strncpy(char *dest, const char *src, size_t n);









void	ft_putchar(char c);

#endif