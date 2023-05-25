/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:25:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 03:47:58 by yatsu            ###   ########.fr       */
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
void	rrr(t_pile *pils, int affichage)
{
	if (affichage)
		ft_printf("rrr\n");
	rra(pils, 0);
	rrb(pils, 0);
}
