/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:16:11 by mravily           #+#    #+#             */
/*   Updated: 2019/09/16 15:26:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned i;
	unsigned j;
	unsigned cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	while (src[cpt] != '\0' && i + cpt < size - 1 && size != 0)
	{
		dest[i + cpt] = src[cpt];
		cpt++;
	}
	if (size != 0)
		dest[i + cpt] = '\0';
	if (size < i)
		return (j + size);
	else
		return (j + i);
}
