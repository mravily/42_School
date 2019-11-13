/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:20:00 by mravily           #+#    #+#             */
/*   Updated: 2019/11/13 20:31:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	if (!(first = ft_lstnew(f(current->content))))
		return (NULL);
	new = first;
	while (current)
	{
		current = current->next;
		if (current)
		{
			if (!(new->next = ft_lstnew(f(current->content))))
				ft_lstclear(&first, del);
			new = new->next;
		}
	}
	return (first);
}
