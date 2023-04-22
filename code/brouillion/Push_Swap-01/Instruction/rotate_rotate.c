/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:53 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 16:39:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils conetnant tout le element important.
	@brief ra et rb en même temps. DONC
	Décale d’une position vers le haut tous les élements de la pile a et b.
	Le premier élément devient le dernier.
*/
void	rr(t_pile *pils)
{
	if (!pils)
		return ;
	ra(pils);
	rb(pils);
}

void	trr(t_pile *pils)
{
	ft_printf("\nTEST rotate A etB :\n");
	use_instruction(7, pils);
}
