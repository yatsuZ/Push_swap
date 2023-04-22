/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:04:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 15:09:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
	@param pils conetnant tout le element important.
	@brief Décale d’une position vers le haut tous les élements de la pile b.
	Le premier élément devient le dernier.
*/
void	rb(t_pile *pils)
{
	t_mayon	*first;
	t_mayon	*last;

	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	last = get_last_mayon(pils->b);
	first = pils->b;
	pils->b = first->next;
	pils->b->previous = 0;
	first->next = 0;
	last->next = first;
	first->previous = last;
	first->position = last->position + 1;
	adjusted_position(-1, pils->b);
}

void	trb(t_pile *pils)
{
	ft_printf("\nTEST rotate B :\n");
	rb(pils);
}
