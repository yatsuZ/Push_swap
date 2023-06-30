/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:25:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/21 14:25:59 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rrr(t_pile *pils, int affichage)
{
	if (affichage)
		ft_printf("rrr\n");
	rra(pils, 0);
	rrb(pils, 0);
}
