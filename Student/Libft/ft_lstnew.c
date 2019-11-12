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
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

ft_lstnew
Prototype t_list *ft_lstnew(void *content);
Fichiers de rendu -
Paramètres #1. Le contenu du nouvel élément.
Valeur de retour Le nouvel element
Fonctions externes autorisées
malloc
Description Alloue (avec malloc(3)) et renvoie un nouvel
élément. la variable content est initialisée à
l’aide de la valeur du paramètre content. La
variable next est initialisée à NULL.
