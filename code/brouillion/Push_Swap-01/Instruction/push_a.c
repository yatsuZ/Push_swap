/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:01:40 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 03:47:44 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Contien juste push_a

/*
	@brief Cette fonction ajuste le positionement des mayons.
	@param decalage int, soit sa sera un decalage negatif ou positif.
	@param pile mayon le mayon qui effectura l'update.
	@return Rien.
*/
void	adjusted_position(int decalage, t_mayon *pil)
{
	if (!pil)
		return ;
	pil->position = pil->position + decalage;
	adjusted_position(decalage, pil->next);
}

/*
	@param pils pointeur de la structure "t_pile" cette structure contiens
	plusieur information comme la pile a et b

	@brief Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/
void	pa(t_pile *pils, int affichage)
{
	t_mayon	*element;

	if (!pils || pils->b == 0)
		return ;
	if (affichage)
		ft_printf("pa\n");
	element = pils->b;
	pils->b = element->next;
	if (pils->b)
		pils->b->previous = 0;
	element->position = 0;
	element->next = 0;
	adjusted_position(-1, pils->b);
	adjusted_position(1, pils->a);
	element->next = pils->a;
	if (element->next)
		element->next->previous = element;
	pils->a = element;
	pils->len_a = pils->len_a + 1;
	pils->len_b = pils->len_b - 1;
}
