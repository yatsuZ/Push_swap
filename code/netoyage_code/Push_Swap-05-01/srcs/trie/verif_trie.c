/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_trie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:39 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 03:44:07 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../header/checker.h"

static int	order(t_mayon *tete, t_mayon *min, t_mayon *c)
{
	t_mayon	*index;

	index = c;
	while (index != min)
	{
		if (c->index > index->index)
			return (1);
		if (index->next == NULL)
			index = tete;
		else
			index = index->next;
	}
	return (0);
}

int	pa_est_il_trier(t_pile *pils)
{
	t_mayon	*current;
	t_mayon	*min;

	if (!pils || pils->a == NULL)
		return (0);
	min = find_min(pils->a);
	current = pils->a;
	while (current)
	{
		if (order(pils->a, min, current))
			return ((-1 * min->position) - 1);
		current = current->next;
	}
	return (min->position);
}
