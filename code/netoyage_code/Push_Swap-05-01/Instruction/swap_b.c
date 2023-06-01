/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:09:15 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:17:11 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sb(t_pile *pils, int affichage)
{
	t_mayon	*second;
	t_mayon	*first;

	if (!pils || pils->b == 0 || pils->len_b <= 1)
		return ;
	if (affichage)
		ft_printf("sb\n");
	first = pils->b;
	second = pils->b->next;
	first->position = 1;
	second->position = 0;
	first->previous = second;
	second->previous = 0;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	pils->b = second;
}
