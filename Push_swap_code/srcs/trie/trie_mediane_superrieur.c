/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_mediane_superrieur.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:58:52 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/02 02:07:32 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	trie_sezieme_max_botom(t_pile *p, int sezieme)
{
	while (p->b->index > sezieme * 8)
	{
		if (p->b->index >= sezieme * 9)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_mayon(p->b)->index < sezieme * 10)
		use_instruction(TRUE, p, 1, RRB);
	while (p->a->index && p->a->index < sezieme * 11)
		use_instruction(TRUE, p, 1, PB);
	while (get_last_mayon(p->b)->index > sezieme * 8)
	{
		if (get_last_mayon(p->b)->index \
		&& get_last_mayon(p->b)->index >= sezieme * 11)
			use_instruction(TRUE, p, 2, RRB, PA);
		else
			use_instruction(TRUE, p, 1, RRB);
	}
	while (p->a->index && p->a->index < sezieme * 13)
		use_instruction(TRUE, p, 1, PB);
}

static void	trie_sezieme_max_mid(t_pile *p, int sezieme)
{
	t_mayon	*last_ma;

	last_ma = get_last_mayon(p->a);
	while (p->a != last_ma)
	{
		if (p->a->index && p->a->index <= sezieme * 14)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->b->index >= sezieme * 13)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	if (p->a->index && p->a->index <= sezieme * 14)
	{
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= sezieme * 13)
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_mayon(p->b)->index > sezieme * 8)
		use_instruction(TRUE, p, 1, RRB);
}

static void	trie_sezieme_max_top(t_pile *p, int sezieme)
{
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= sezieme * 15)
			use_instruction(TRUE, p, 1, RB);
	}
	while (get_last_mayon(p->b)->index > sezieme * 8)
		use_instruction(TRUE, p, 1, RRB);
}

void	trie_median_max(t_pile *p, int sezieme)
{
	t_mayon	*last_ma;

	last_ma = get_last_mayon(p->a);
	while (p->a != last_ma)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		else if (p->a->index <= sezieme * 12)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->b->index >= sezieme * 10)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	if (p->a->index && p->a->index <= sezieme * 12)
	{
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index <= sezieme * 10)
			use_instruction(TRUE, p, 1, RB);
	}
	trie_sezieme_max_botom(p, sezieme);
	trie_sezieme_max_mid(p, sezieme);
	trie_sezieme_max_top(p, sezieme);
}
