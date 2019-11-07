<<<<<<< HEAD:Student/Libft/ft_isalnum.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:56 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 15:39:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_isalnum(int c)
{

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:31:31 by mravily           #+#    #+#             */
/*   Updated: 2019/11/05 13:31:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	unsigned char alnum;

	alnum = c;
	if ((alnum >= 'a' && alnum <= 'z') || (alnum >= 'A' && alnum <= 'Z') ||
		(alnum >= '0' && alnum <= '9'))
		return (1);
	return (0);
}
>>>>>>> 2f0b94d96dbebde8e0c96cfe162370bc48ff3ee1:Student/Libft/ft_alnum.c
