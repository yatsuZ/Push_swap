/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:05:53 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 03:47:49 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@param pils conetnant tout le element important.
	@brief ra et rb en même temps. DONC
	Décale d’une position vers le haut tous les élements de la pile a et b.
	Le premier élément devient le dernier.
*/
void	rr(t_pile *pils, int affichage)
{
	if (affichage)
		ft_printf("rr\n");
	ra(pils, 0);
	rb(pils, 0);
}
