/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 16:16:46 by yzaoui           ###   ########.fr       */
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
		else
			use_instruction(TRUE, p, 1, PB);
		if (p->b->index >= median + (median / 2))
			use_instruction(TRUE, p, 1, RB);
	}
}

void	trie_siziem_mid(t_pile *p, int huitieme)
{
	//trie le 3iem quartille
	while (p->b->index >= (huitieme * 2))
	{
		if (p->b->index >= (huitieme * 3) - (huitieme / 2))
			use_instruction(TRUE, p, 1, RB);
		else
			use_instruction(TRUE, p, 1, PA);
	}
	while (p->a->index >= huitieme * 2)
		use_instruction(TRUE, p, 1, PB);
	while (get_last_mayon(p->b)->index >= huitieme * 2)
		use_instruction(TRUE, p, 1, RRB);


}

void	trie_siziem_extreme(t_pile *p, int huitieme)
{
/// trie 1ier sexieme
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

void	trie_quart_min(t_pile *p, int quartille)
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
	// trie_siziem_mid(p, quartille / 2);
	trie_siziem_extreme(p, quartille / 2);

}

void	trie_quart_max(t_pile *p, int huitiemme)
{
	if (!p->b)
		return ;
	while (p->b->index >= huitiemme * 4)
	{
		if (p->b->index < huitiemme * 5)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RB);
	}
	while (p->b->index >= huitiemme * 4)
	{
		if (p->b->index >= huitiemme * 7)
			use_instruction(TRUE, p, 1, PA);
		else
			use_instruction(TRUE, p, 1, RRB);
	}
	if (p->b->index < huitiemme * 4)
		use_instruction(TRUE, p, 1, RB);
}
void	use_swap(t_pile *p, int instruction)
{
	ft_printf("\n\n\nALORS ??\n\n\n");
	if (p->b->next && p->b->index < p->b->next->index \
	&& p->len_a > 4 && p->a->index > p->a->next->index)
		use_instruction(TRUE, p, 1, SS);
	else if (p->b->next && p->b->index < p->b->next->index)
		use_instruction(TRUE, p, 1, SB);
	else if (p->len_a > 4 && p->a->index > p->a->next->index)
		use_instruction(TRUE, p, 1, SA);
	use_instruction(TRUE, p, 1, instruction);
}

void pretrie_huitieme(t_pile *p, int huitiemme, int unite)
{
	while (((p->a->index >= (unite * huitiemme) - huitiemme) \
	&& (p->a->index <= (unite * huitiemme))) \
	|| (p->a->index == 0 || p->a->index == p->len_total - 1))
	{
		if (p->b && p->b->next && p->b->index < p->b->next->index \
		&& p->len_a > 4 && p->a->index > p->a->next->index)
			use_instruction(TRUE, p, 1, SS);
		else if (p->b && p->b->next && p->b->index < p->b->next->index)
			use_instruction(TRUE, p, 1, SB);
		else if (p->len_a > 4 && p->a->index > p->a->next->index)
			use_instruction(TRUE, p, 1, RA);
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(TRUE, p, 1, RA);
		use_instruction(TRUE, p, 1, PB);
	}

}

void amalgame_dans_b(t_pile *p, int huitiemme)
{
	while (p->a->index <= huitiemme * 5)
	{
		if (p->a->index >= (huitiemme * 4) + (huitiemme / 2))
			use_instruction(1, p, 1, RA);
		else
			use_instruction(1, p, 1, PB);
	}
	while (get_last_mayon(p->a)->index && get_last_mayon(p->a)->index <= huitiemme * 7)
			use_instruction(1, p, 2, RRA, PB);

	while (get_last_mayon(p->b)->index > huitiemme)
		use_instruction(1, p, 1, RRB);
	while (p->a->index != 0 && p->a->index != p->len_total - 1)
	{
		if (p->a->index >= p->len_total - (huitiemme / 2))
			use_instruction(1, p, 1, RA);
		else
			use_instruction(1, p, 1, PB);
	}
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(1, p, 1, RA);
		else
			use_instruction(1, p, 1, PB);
	}
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


// encore divise par 2 chaque mayon et faire mon sisteme de optimisation de trie

void	trie_rapide(t_pile *p)
{
	trie_median_min(p, (p->len_total / 8) * 4);
	trie_quart_min(p, (p->len_total / 8) * 2);
	trie_median_max(p,(p->len_total / 8) * 4);
	trie_quart_max(p, (p->len_total / 8));
	// amalgame_dans_b(p, p->len_total / 8);
	// while (p->b)
	// 	trie(p);
	// faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
}
