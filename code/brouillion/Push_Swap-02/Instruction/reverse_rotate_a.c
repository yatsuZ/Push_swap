/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:22:42 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 03:23:54 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief Permet de recuperer le dernier mayons d'un pile
	@param pil poitneur de mayon
	@return le dernier mayon de la pile. Null si la pile est vide.
*/
t_mayon	*get_last_mayon(t_mayon *pil)
{
	if (!pil)
		return (0);
	else if (pil->next == 0)
		return (pil);
	return (get_last_mayon(pil->next));
}

/*
	@brief Décale d’une position vers le bas tous les élements de la pile a.
	Le dernier élément devient le premier.
	@param pils pointeur de la structure piles contenan tout.
	@return rien.
*/
void	rra(t_pile *pils, int affichage)
{
	t_mayon	*last;

	if (affichage)
		ft_printf("rra\n");
	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	last = get_last_mayon(pils->a);
	if (last->previous)
		last->previous->next = 0;
	last->previous = 0;
	last->position = 0;
	adjusted_position(+1, pils->a);
	last->next = pils->a;
	if (last->next)
		last->next->previous = last;
	pils->a = last;
}