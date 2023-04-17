/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:02:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/17 15:55:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils pointeur de la structure "t_pile" cette structure contiens
	plusieur information comme la pile a et b

	@brief Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/
void	push_b(t_pile *pils)
{
	t_mayon	*element;

	if (pils->a == 0)
		return ;
	element = pils->a;
	pils->a = element->next;
	if (pils->a)
		pils->a->previous = 0;
	element->position = 0;
	element->next = 0;
	adjusted_position(-1, pils->a);
	adjusted_position(1, pils->b);
	element->next = pils->b;
	if (element->next)
		element->next->previous = element;
	pils->b = element;
	pils->len_b = pils->len_b + 1;
	pils->len_a = pils->len_a - 1;
}

