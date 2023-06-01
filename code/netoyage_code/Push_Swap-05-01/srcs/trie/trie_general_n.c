/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:03:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 15:47:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	trie_seizieme_min(t_pile *p, int seizieme)
{
	int	quart;
	int	huitieme;
	int	douxieme;

	quart = seizieme * 4;
	huitieme = seizieme * 2;
	douxieme =  huitieme / 2;
	while (p->b->index <= quart)
	{
		if (p->b->index >= quart - huitieme - douxieme)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index >= quart)
	{
		if (p->b->index <= quart + huitieme + douxieme)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->a->index >= quart)
	{
		if (p->a->index >= quart + douxieme)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->b->index >= quart + douxieme + seizieme)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	//
	while (p->b->index > quart)
		use_instruction(TRUE, p, 1, RB);
	//
	while (p->a->index <= quart)
	{
		if (p->a->index <= quart - douxieme - seizieme)

			use_instruction(TRUE, p, 1, PB);
		else
			use_instruction(TRUE, p, 1, RA);
	}
	//
	while ((get_last_mayon(p->a)->index <= quart))
	{
		use_instruction(TRUE, p, 2, RRA, PB);
		if (p->b->index >= 3 * seizieme)
			use_instruction(TRUE, p, 1, RB);
	}
	//
	while ((get_last_mayon(p->b)->index < quart + seizieme))
		use_instruction(TRUE, p, 1, RRB);
	//
	while ((get_last_mayon(p->a)->index <= quart * 2))
	{
		use_instruction(TRUE, p, 2, RRA, PB);
		if (p->b->index >= douxieme - seizieme)
			use_instruction(TRUE, p, 1, RB);
	}
	//
	while (p->b->index <= quart)
		use_instruction(TRUE, p, 1, RB);
}

void	trie_quart_min(t_pile *p, int sezieme)
{
	int	median;
	int	quart;

	median = sezieme * 8;
	quart = sezieme * 4;
	while (p->len_b + 1 <= median)
	{
		if (p->a->index == 0)
			use_instruction(TRUE, p, 1, RA);
		if (p->a->index <= median)
		{
			use_instruction(TRUE, p, 1, PB);
			if (p->len_b > 1 && p->b->index >= quart)
				use_instruction(TRUE, p, 1, RB);
		}
		else
			use_instruction(TRUE, p, 1, RA);
	}
	trie_seizieme_min(p, sezieme);
}

void	trie_seizieme_max(t_pile *p, int seizieme)
{
	int	quart;
	int	huitieme;
	int	douxieme;

	quart = seizieme * 4;
	huitieme = seizieme * 2;
	douxieme =  huitieme / 2;
	while (p->b->index > quart * 2)
	{
		if (p->b->index >= quart - huitieme - douxieme)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	//
	while ((get_last_mayon(p->b)->index > quart))
	{
		if (get_last_mayon(p->b)->index < p->len_total - seizieme)
			use_instruction(TRUE, p, 2, RRB, PA);
		else
			use_instruction(TRUE, p, 1, RRB);
	}
	//
	while (p->b->index > quart * 3)
		use_instruction(TRUE, p, 1, RB);
	//

	// while (p->a->index >= quart)
	// {
	// 	if (p->a->index >= quart + douxieme)
	// 	{
	// 		use_instruction(TRUE, p, 1, PB);
	// 		if (p->b->index >= quart + douxieme + seizieme)
	// 			use_instruction(TRUE, p, 1, RB);
	// 	}
	// 	else
	// 		use_instruction(TRUE, p, 1, RA);
	// }
	// while (p->a->index <= quart)
	// {
	// 	if (p->a->index <= quart - douxieme - seizieme)
	// 	{

	// 		use_instruction(TRUE, p, 1, PB);
	// 	}
	// 	else
	// 		use_instruction(TRUE, p, 1, RA);
	// }
	// //
	// while ((get_last_mayon(p->a)->index <= quart))
	// {
	// 	use_instruction(TRUE, p, 2, RRA, PB);
	// 	if (p->b->index >= 3 * seizieme)
	// 		use_instruction(TRUE, p, 1, RB);
	// }
	// //
	// while ((get_last_mayon(p->b)->index < quart))
	// 	use_instruction(TRUE, p, 1, RRB);
	// //
	// while ((get_last_mayon(p->a)->index <= quart * 2))
	// {
	// 	use_instruction(TRUE, p, 2, RRA, PB);
	// 	if (p->b->index >= douxieme - seizieme)
	// 		use_instruction(TRUE, p, 1, RB);
	// }
	// //
	// while (p->b->index <= quart)
	// 	use_instruction(TRUE, p, 1, RB);
}

void	trie_quart_max(t_pile *p, int sezieme)
{
	int	median;
	int	quart;

	median = sezieme * 8;
	quart = sezieme * 4;
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= median + quart)
				use_instruction(TRUE, p, 1, RB);
	}
	trie_seizieme_max(p, sezieme);
}

void trie(t_pile *p)
{
	t_mayon *last_ma;

	last_ma = get_last_mayon(p->a);
	if (p->b->index > p->a->index && p->b->index < p->a->next->index)
	{
		if (p->b->next && p->b->next->next && p->b->next->index < p->b->next->next->index)
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
	return (trie(p));
}


void	trie_rapide(t_pile *p)
{
	int	sezieme;

	sezieme = p->len_total / 16;
	trie_quart_min(p, sezieme);
	trie_quart_max(p,sezieme);
	// while (p->b)
	// 	trie(p);
	// faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
}
