/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:22:42 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/21 14:25:41 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rra(t_pile *pils, int affichage)
{
	t_mayon	*last;

	if (affichage)
		ft_printf("rra\n");
	if (!pils || pils->a == 0 || pils->len_a <= 1)
		return ;
	last = get_last_mayon(pils->a);
	if (last->previous)
		last->previous->next = 0;
	last->previous = 0;
	last->position = 0;
	adjusted_position(+1, pils->a);
	last->next = pils->a;
	if (last->next)
		last->next->previous = last;
	pils->a = last;
}
