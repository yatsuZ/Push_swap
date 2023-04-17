/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:03:15 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/17 19:18:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils conetnant tout le element important.
	@brief sa et sb en même temps. DONC
	Intervertit les 2 premiers éléments au sommet de la pile a et b.
	Si les 2 pile son vide ne fais rien.
	Si une des 2 piles est vide alors ne ais rien avec la pile vide.
*/
void	ss(t_pile *pils)
{
	sa(pils);
	sb(pils);
}
