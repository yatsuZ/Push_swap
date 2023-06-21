/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:16:33 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/21 14:48:02 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	trie_fin(t_pile *p)
{
	t_mayon	*last_ma;

	last_ma = get_last_mayon(p->a);
	if (p->b->index > p->a->index && p->b->index < p->a->next->index)
	{
		if (p->b->next && p->b->next->next \
		&& p->b->next->index < p->b->next->next->index)
			use_instruction(TRUE, p, 2, PA, SS);
		else
			use_instruction(TRUE, p, 2, PA, SA);
		return ;
	}
	if (p->b->index > last_ma->index && p->b->index < p->a->index)
	{
		use_instruction(TRUE, p, 1, PA);
		return ;
	}
	else if (p->b->index > last_ma->index)
		use_instruction(TRUE, p, 1, RA);
	else
		use_instruction(TRUE, p, 1, RRA);
	return (trie_fin(p));
}

static void	pre_trie(t_pile *p, int sezieme)
{
	trie_median_min(p, sezieme);
	trie_median_max(p, sezieme);
}

static void	trie(t_pile *p)
{
	while (p->b)
		trie_fin(p);
	faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
}

void	trie_rapide(t_pile *p)
{
	pre_trie(p, p->len_total / 16);
	trie(p);
}
