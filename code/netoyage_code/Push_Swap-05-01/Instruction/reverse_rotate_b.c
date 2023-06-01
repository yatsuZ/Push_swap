/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:23:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:16:39 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rrb(t_pile *pils, int affichage)
{
	t_mayon	*last;

	if (affichage)
		ft_printf("rrb\n");
	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	last = get_last_mayon(pils->b);
	if (last->previous)
		last->previous->next = 0;
	last->previous = 0;
	last->position = 0;
	adjusted_position(+1, pils->b);
	last->next = pils->b;
	if (last->next)
		last->next->previous = last;
	pils->b = last;
}
