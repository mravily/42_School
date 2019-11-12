/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:05:05 by marvin            #+#    #+#             */
/*   Updated: 2019/11/12 20:05:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if  (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

Function name ft_lstadd_front
Prototype void ft_lstadd_front(t_list **alst, t_list *new);
Fichiers de rendu -
Paramètres #1. L’adresse du pointeur vers le premier élément
de la liste.
#2. L’adresse du pointeur vers l’élément à rajouter
à la liste.
Valeur de retour None
Fonctions externes autorisées
None
Description Ajoute l’élément new au début de la liste