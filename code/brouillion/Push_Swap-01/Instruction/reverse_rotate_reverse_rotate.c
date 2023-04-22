/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:25:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 16:39:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief fais rra et rrb en meme temp.
	Décale d’une position vers le bas tous les élements de
	la pile a et b.
	Le dernier élément devient le premier.
	@param pils conetnant tout le element important.
*/
void	rrr(t_pile *pils)
{
	if (!pils)
		return ;
	rra(pils);
	rrb(pils);
}

void	trrr(t_pile *pils)
{
	ft_printf("\nTEST Reverse rotate A et B:\n");
	use_instruction(4, pils);
}
