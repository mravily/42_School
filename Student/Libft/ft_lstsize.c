/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:27:59 by marvin            #+#    #+#             */
/*   Updated: 2019/11/12 20:27:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
}

Function name ft_lstsize
Prototype int ft_lstsize(t_list *lst);
Fichiers de rendu -
Paramètres #1. Le début de la liste.
Valeur de retour Taille de la liste.
Fonctions externes autorisées
None
Description Compte le nombre d’éléments de la liste.