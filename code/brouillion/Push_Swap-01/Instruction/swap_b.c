/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:09:15 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 15:10:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
	@param pils conetnant tout le element important.
	@brief Intervertit les 2 premiers éléments au sommet de la pile b.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sb(t_pile *pils)
{
	t_mayon	*second;
	t_mayon	*first;

	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	first = pils->b;
	second = pils->b->next;
	first->position = 1;
	second->position = 0;
	first->previous = second;
	second->previous = 0;
	first->next = second->next;
	second->next = first;
	pils->b = second;
}

void	tsb(t_pile *pils)
{
	ft_printf("\nTEST Swap B :\n");
	sb(pils);
}
