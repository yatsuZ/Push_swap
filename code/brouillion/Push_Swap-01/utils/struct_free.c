/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:33:05 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/27 17:00:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Gestion de free de structure

// free une lise de mayon,
// (une pile) a partir de la tete
// return NULL

/*
	@brief Free tout les mayons qui suit le parametre et lui compris
	@param s pointeur de pointeur de structure "t_mayon", ** car comme sa
	je peux dire que le pointeur sera egale a nul et poura se free tout seul.
	@return ne retourne rien.
*/
void	*free_pile(t_mayon **s)
{
	if (!s || !(*s))
		return (NULL);
	(*s)->index = 0;
	(*s)->position = 0;
	(*s)->val = 0;
	(*s)->trie = 0;
	(*s)->cplacement = 0;
	(*s)->crangement = 0;
	(*s)->rangement = 0;
	(*s)->previous = NULL;
	free_pile(&(*s)->next);
	(*s)->next = NULL;
	free(*s);
	*s = NULL;
	return (NULL);
}

/*
	@brief Free toute la structure t_pile lui compris
	@param p pointeur de pointeur de structure "t_pile", ** car comme sa
	je peux dire que le pointeur sera egale a nul et poura se free tout seul.
	@return ne retourne rien.
*/
void	*free_struct(t_pile **p)
{
	if (!p || !(*p))
		return (NULL);
	free_pile(&((*p)->a));
	(*p)->a = NULL;
	free_pile(&((*p)->b));
	(*p)->b = NULL;
	(*p)->len_a = 0;
	(*p)->len_b = 0;
	(*p)->len_total = 0;
	free(*p);
	*p = NULL;
	return (NULL);
}
