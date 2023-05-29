/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_5_ou_moin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:21:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/29 20:51:55 by yzaoui           ###   ########.fr       */
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
	// while (p->b)
	// 	add_into_pa(p, p->b);
	add_into_pa(p, p->b);
	affichage_struct_all(p);
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
	ft_printf("Le mayon que l'on shouaite place il est dans la pile b :\n");
	affichage_mayon(mayon_b, 0);
	ft_printf("Le mayon le plus proche dans pile a :\n");
	affichage_mayon(suivant, 0);
	ft_printf("Le mayon de la pile b sera place a la tete de :\n");
	if (suivant->index < mayon_b->index)
	{
		if (suivant->next == NULL)
			suivant = p->a;
		else
			suivant = suivant->next;
	}
	affichage_mayon(suivant, 0);
}
