/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:36:35 by mravily           #+#    #+#             */
/*   Updated: 2019/11/13 19:02:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		del(tmp->content);
		*lst = tmp->next;
		free(tmp);
		tmp = *lst;
	}
	lst = NULL;
}
