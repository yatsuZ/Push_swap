/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:55:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/16 15:05:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief verifie si la liste de mayon et trier par ordre croissant,
	sans prendre en compte le point de depart.
	@param tete mayon tete
	@return True si trier, False si non. (True = 0).
*/
int	p_trier(t_mayon *tete)
{
	int		i;
	t_mayon	*current;

	i = -1;
	current = tete;
	while (current)
	{
		if (i > current->index)
		{
			if (current->index == 0)
				i = 0;
			else
				return (FALSE);
		}
		else
			i = current->index;
		if (tete->index && current->next == NULL)
			return (current->index < tete->index);
		current = current->next;
	}
	return (TRUE);
}

/*
	@brief Mets tout les mayons de A dans B s'arrete soit quand ce qu'il reste
	dans la pile a et trier ou, qu'il reste le plus petit, grand et la median.
*/
void	transvase(t_pile *p)
{
	while (p->len_a > 3 && !p_trier(p->a))
	{
		if (p->a->index == 0 || p->a->index == p->len_total - 1 || \
		p->a->index == (p->len_total - 1) / 2)
			use_instruction(TRUE, p, 1, RA);
		else
			use_instruction(TRUE, p, 1, PB);
	}
}

/*
	@brief implemente pour chaque mayon de la pile B.
	leur coup placement, coup rangement, rangement et trie.
*/
void	coup_trie(t_pile *p, t_mayon *mb)
{
	mb->cplacement = cout_placement(mb->position, p->len_b);
	mb->crangement = coup_rangement(p, mb);
	if (mb->cplacement < 0)
		mb->trie = mb->cplacement * -1;
	else
		mb->trie = mb->cplacement;
	if (mb->crangement < 0)
		mb->trie = mb->trie + mb->crangement * -1;
	else
		mb->trie = mb->trie + mb->crangement;
	mb->trie = mb->trie + mb->rangement;
}

void	ft_iter_mb(t_pile *p, t_mayon *mayon, \
void (*f)(t_pile *p, t_mayon *mayon))
{
	if (!p || !mayon || !f)
		return ;
	f(p, mayon);
	if (!mayon->next)
		return ;
	ft_iter_mb(p, mayon->next, f);
}

/*
	@brief La fonction qui s'occupe de trier + ranger tout les cas de piles.
	@param pil -> ma structure pile contenant tout mes information importante.
*/
void	trie_generale(t_pile *p)
{
	int	patrier;

	ft_printf("Trie generale :\n");
	if (!p)
		return ;
	transvase(p);
	patrier = p_trier(p->a);
	if (!patrier)
		p2_trie_p3(p, (find_index(p, 0)->index * (-1)) - 1);
	ft_iter_mb(p, p->b, coup_trie);
	affichage_struct_all(p);
}
