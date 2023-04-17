/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:01:54 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/17 19:09:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils conetnant tout le element important.
	@brief Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	sa(t_pile *pils)
{
	t_mayon	*second;
	t_mayon	*first;

	if (pils->a == 0 || pils->len_a <= 1)
		return ;
	first = pils->a;
	second = pils->a->next;
	first->position = 1;
	second->position = 0;
	first->previous = second;
	second->previous = 0;
	first->next = second->next;
	second->next = first;
	pils->a = second;
}
