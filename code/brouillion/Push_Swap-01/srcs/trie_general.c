/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:55:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/04/27 17:40:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief Mets tout les mayons de A dans B s'arrete soit quand ce qu'il reste
	dans la pile a et trier ou, qu'il reste le plus petit, grand et la median.
*/
void	transvase(t_pile *p)
{

	while (p->len_a > 3 && validation_de_trie_PA(p, 0) < 0)
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1 || \
		p->a->index == (p->len_total - 1) / 2)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
	}
}

void	coup_placement_b(t_mayon *pb, int len)
{
	pb->cplacement = cout_placement(pb->position, len);
}

void	print_coup(t_mayon *p)
{
	if (p==NULL)
		return ;
	ft_printf("valeur = %d  \t| CP = %d\n", p->val, p->cplacement);
	print_coup(p->next);
}

/*
	@brief La fonction qui s'occupe de trier + ranger tout les cas de piles.
	@param pil -> ma structure pile contenant tout mes information importante.
*/
void	trie_generale(t_pile *p)
{
	ft_printf("Trie generale :\n");
	if (!p)
		return ;
	transvase(p);
	ft_mayon_iter(p->b, p->len_b, coup_placement_b);
	affichage_struct_all(p);
	print_coup(p->b);
}
