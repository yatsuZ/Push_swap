/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/30 19:44:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	trie_median_min(t_pile *p, int median)
{
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
}

void	trie_median_max(t_pile *p, int median)
{
	while (p->len_a != 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= median + (median / 2))
			use_instruction(TRUE, p, 1, RB);
	}
}

void	trie_quart_min(t_pile *p, int quartille)
{
	if (!p->b)
		return ;
	while (p->b->index >= quartille)
	{
		if (p->b->index > quartille + (quartille / 2))
			use_instruction(TRUE, p, 1, PA);
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
	while (p->a->index <= quartille * 2)
		use_instruction(TRUE, p, 1, PB);
}

void	trie_quart_max(t_pile *p, int huitiemme)
{
	if (!p->b)
		return ;
	while (p->b->index >= huitiemme * 4)
	{
		if (p->b->index >= huitiemme * 7)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RRB);
	}
	if (p->b->index < huitiemme * 4)
		use_instruction(TRUE, p, 1, RB);
	while (p->b->index >= huitiemme * 4)
	{
		if (p->b->index < huitiemme * 5)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
}

void amalgame_dans_b(t_pile *p, int huitiemme)
{
	while (p->a->index < huitiemme * 7)
		use_instruction(TRUE, p, 1, PB);
	while (p->a->index >= huitiemme * 7 || !p->a->index)
		use_instruction(TRUE, p, 1, RA);
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
	}
}

void amalgame_dans_a(t_pile *p, int huitiemme)
{
	while (p->b->index > huitiemme)
		use_instruction(TRUE, p, 1, PA);
	while (p->b->index <= huitiemme)
		use_instruction(TRUE, p, 1, RB);
	while (p->b->index < huitiemme * 4)
		use_instruction(TRUE, p, 1, PA);
	while (p->b->index > huitiemme * 6 || p->b->index < huitiemme * 5)
		use_instruction(TRUE, p, 1, RRB);
	use_instruction(TRUE, p, 1, RB);
	while (p->b)
		use_instruction(TRUE, p, 1, PA);
	while (!p->a->index || p->a->index > huitiemme)
		use_instruction(TRUE, p, 1, RA);
	amalgame_dans_b(p, huitiemme);
}

void	trie_generale(t_pile *p)
{
	trie_median_min(p, p->len_total / 2);
	trie_quart_min(p, p->len_total / 4);
	trie_median_max(p, p->len_total / 2);
	trie_quart_max(p, p->len_total / 8);
	amalgame_dans_a(p, p->len_total / 8);
	//finish_sort(p);
	while (p->b)// teste a suprimer
		add_into_pa(p, p->b);
	faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
}
