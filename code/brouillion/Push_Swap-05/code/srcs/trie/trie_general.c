/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/31 20:53:08 by yzaoui           ###   ########.fr       */
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
// void amalgame_dans_b(t_pile *p, int huitiemme)
// {
// 	pretrie_huitieme(p, huitiemme, 1);
// }

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

void add_into_pa_general(t_pile *p)
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
	return (add_into_pa_general(p));
}

void	go_to_unit(t_pile *p, int min, int max)
{
	t_mayon	*first_unite;

	first_unite = p->b;
	while (!(first_unite->index >= min && first_unite->index <= max) \
	|| !(!first_unite->previous || (first_unite->previous->index >= min && first_unite->previous->index <= max)))
	{
		first_unite = first_unite->next;
	}
	ft_printf("first_unite->index = %d\nfirst_unite->position = %d\nmin = %d et max = %d\n", first_unite->index, first_unite->position, min, max);
	faire_r_ou_rr(p, first_unite->position, PILE_B);
}

void	trie_huitieme(t_pile *p, int huitiemme, int unite)
{
	int max;
	int min;

	if (unite == 8)
		max = p->len_total;
	else
		max = (huitiemme * unite);
	min = (huitiemme * unite) - huitiemme;
	go_to_unit(p, min, max);
	while (p->b->index >= min && p->b->index <= max)
		add_into_pa_general(p);
	printf("FIN\n");
}


void	finish_short(t_pile *p, int huitiemme)
{
	trie_huitieme(p, huitiemme, 8);
	trie_huitieme(p, huitiemme, 7);
	// trie_huitieme(p, huitiemme, 6);
	// trie_huitieme(p, huitiemme, 8);
	// trie_huitieme(p, huitiemme, 8);
	// trie_huitieme(p, huitiemme, 8);
	// trie_huitieme(p, huitiemme, 8);
	// trie_huitieme(p, huitiemme, 8);
}

void tout_dans_b(t_pile *p)
{
	while (p->len_a > 2)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1)
			use_instruction(1, p, 1, RA);
		use_instruction(1, p, 1, PB);
	}

}

// encore divise par 2 chaque mayon et faire mon sisteme de optimisation de trie

void	trie_generale(t_pile *p)
{
	int	tour;

	tour = 10;
	trie_median_min(p, (p->len_total / 8) * 4);
	trie_quart_min(p, (p->len_total / 8) * 2);
	trie_median_max(p,(p->len_total / 8) * 4);
	trie_quart_max(p, (p->len_total / 8));
	amalgame_dans_a(p, p->len_total / 8);
	// tout_dans_b(p);
	// finish_short(p, p->len_total / 8);
	// while (p->b)
	// 	add_into_pa_general(p);
	// faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
	// affichage_struct_all(p);
}
