/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:02:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 04:04:13 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils pointeur de la structure "t_pile" cette structure contiens
	plusieur information comme la pile a et b

	@brief Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/
void	pb(t_pile *pils, int affichage)
{
	t_mayon	*element;

	if (!pils || pils->a == 0)
		return ;
	if (affichage)
		ft_printf("pb\n");
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
