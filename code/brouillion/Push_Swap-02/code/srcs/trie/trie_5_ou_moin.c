/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_5_ou_moin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:21:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/29 21:57:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	trie_5_ou_moin(t_pile *p)
{
	if (p->len_total == 4)
		ft_printf("Trie de 4\n");
	else
		ft_printf("Trie de 5\n");
	while (p->len_a > 3)
		use_instruction(1, p, 1, PB);
	p2_trie_p3(p, pa_est_il_trier(p, 0));
	// add_into_pa(p, p->b);
	// add_into_pa(p, p->b);
	// while (p->b)
	// 	add_into_pa(p, p->b);
	// faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
	return ;
}

/*
	@brief Prend un mayon b (on pars du principe qu'il est au sommet de la pile b)
	et l'ajoute correctement dans la pile a
	! Condition il faute que la pile a soit dea trier.
	@param p *t_pile contient toute ma pile pour efectuer des mouve.
	@param mayon_b *t_mayon le mayon b qu'on shouaite place.
	@return Ne return rien mais effectue des mouvement
*/
void	add_into_pa(t_pile *p, t_mayon *mayon_b)
{
//va regarder lindex de mayon b cherche lindex le plus proche dans pile a puis esaaye de metre le mayon du plus proche index de mayon b au sommet puis fini par pa.
	t_mayon	*suivant;

	suivant = find_most_close(p->a, mayon_b);
	if (suivant->index < mayon_b->index)
	{
		if (suivant->next == NULL)
			suivant = p->a;
		else
			suivant = suivant->next;
	}
	faire_r_ou_rr(p, suivant->position, PILE_A);
	use_instruction(TRUE, p, 1, PA);
}
