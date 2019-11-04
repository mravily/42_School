/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:33:39 by mravily           #+#    #+#             */
/*   Updated: 2019/09/06 10:04:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		else
			i++;
	}
	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	i = 1;
	while (str[i])
	{
		if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z') || (str[i - 1] >= 'a'
		&& str[i - 1] <= 'z') || (str[i - 1] >= '0' && str[i - 1] <= '9'))
			i++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else
			i++;
	}
	return (str);
}
