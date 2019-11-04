/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:31:54 by mravily           #+#    #+#             */
/*   Updated: 2019/09/15 04:44:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		i++;
		if (to_find[j] == '\0')
			return (str + (i - j));
	}
	return (0);
}
