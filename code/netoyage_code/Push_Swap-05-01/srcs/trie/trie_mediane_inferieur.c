/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_mediane_inferieur.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:12:18 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/02 02:06:36 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	trie_quart_min(t_pile *p, int quartille)
{
	if (!p->b)
		return ;
	while (p->b->index >= quartille)
	{
		if (p->b->index > quartille + (quartille / 2))
		{
			use_instruction(TRUE, p, 1, PA);
		}
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= quartille)
	{
		if (p->b->index < quartille - (quartille / 2))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
}

static void	trie_siziem_min_extreme(t_pile *p, int huitieme)
{
	while (p->a->index <= huitieme)
	{
		if (!p->a->index)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= (huitieme / 2))
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= huitieme)
		use_instruction(TRUE, p, 1, RB);
	while (p->a->index <= huitieme * 4)
	{
		if (!p->a->index)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= (huitieme * 4) - (huitieme / 2))
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_mayon(p->b)->index > huitieme)
		use_instruction(TRUE, p, 1, RRB);
}

static void	trie_siziem_min_mid(t_pile *p, int sezieme)
{
	while (p->b->index >= (sezieme * 4))
	{
		if (p->b->index >= (sezieme * 5))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index <= (sezieme * 4))
	{
		if (p->b->index <= (sezieme * 3))
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->a->index <= (sezieme * 4))
		use_instruction(TRUE, p, 2, PB, RB);
	while (p->a->index >= sezieme)
		use_instruction(TRUE, p, 1, PB);
}

void	trie_median_min(t_pile *p, int sezieme)
{
	int	median;
	int	huitieme;

	huitieme = sezieme * 2;
	median = sezieme * 8;
	while (p->len_b + 1 <= median)
	{
		if (p->a->index == 0)
			use_instruction(TRUE, p, 1, RA);
		if (p->a->index <= median)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->len_b > 1 && p->b->index <= median / 2)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	trie_quart_min(p, sezieme * 4);
	trie_siziem_min_mid(p, sezieme);
	trie_siziem_min_extreme(p, huitieme);
}
