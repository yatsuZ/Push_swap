/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:03:47 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 15:09:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
	@param pils conetnant tout le element important.
	@brief Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier.
*/
void	ra(t_pile *pils)
{
	t_mayon	*first;
	t_mayon	*last;

	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	last = get_last_mayon(pils->a);
	first = pils->a;
	pils->a = first->next;
	pils->a->previous = 0;
	first->next = 0;
	last->next = first;
	first->previous = last;
	first->position = last->position + 1;
	adjusted_position(-1, pils->a);
}

void	tra(t_pile *pils)
{
	ft_printf("\nTEST rotate A :\n");
	ra(pils);
}
