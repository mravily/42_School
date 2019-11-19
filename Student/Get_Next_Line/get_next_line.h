#ifndef _GET_NEXT_LINE_
# define _GET_NEXT_LINE_

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# define BUFFER_SIZE 32

char		*ft_strcpy(char *dest, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);

#endif