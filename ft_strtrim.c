/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 07:55:40 by mravily           #+#    #+#             */
/*   Updated: 2019/11/06 07:55:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int        s_len(char const *s1)
{
    int i;

    i = 0;
    while (s1[i])
        i++;
    return (i);
}

static int    compt_set(char const *s1, char const *set)
{
  int i;
  int j;
  int size_s1;
  int cmpt;
  int size_set;
  
  i = 0;
  j = 0;
  cmpt = 0;
  size_s1 = s_len(s1);
  size_set = s_len(set);
  while (i < size_set)
  {
    j = 0;
    while (set[j])
        {
          if (s1[i] == set[j])
            cmpt++;        
          j++;
        }
        i++;
    }
  j = 0;
  while (size_s1 > size_set)
  {
    j = 0;
    while (set[j])
      {
        if (s1[size_s1] == set[j])
          cmpt++;
        j++;
      }
    size_s1--;
  }
  return (cmpt);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     j;
    int     k;
    char    *str;
    int     size_s1;

    i = 0;
    j = 0;
    k = 0;
    size_s1 = s_len(s1);
    if (!(str = (char *)malloc(sizeof(char) * (s_len(s1) - compt_set(s1, set)) + 1)))
        return (NULL);
    while (i < size_s1)
    {
        while (set[j])
        {
          if (s1[i] == set[j])
            i++;
          j++;
        }
      str[k] = s1[i];
      k++;
      i++;
    }
    printf("j = %d\n", j);
    printf("i = %d\n", i);
    while (i > 0)
    {
        while (j == 0)
        {
          if (s1[i] == set[j])
            i--;
          j--;
        }
      str[k] = s1[i];
      k++;
      i--;
    }
    return (str);
}

int        main(void)
{
    const char    s1[] = {"xoxoTest Stringxoxo"};
    char        set[] = {"xoxo"};

    printf("return = %d\n",compt_set(s1, set));
    puts(ft_strtrim(s1, set));
}
