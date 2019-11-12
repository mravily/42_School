/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:47:43 by mravily           #+#    #+#             */
/*   Updated: 2019/11/12 13:58:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	void	*new;

	if (!(new = (t_list *)malloc(sizeof(content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
}
