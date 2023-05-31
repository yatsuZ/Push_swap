/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_5_ou_moin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:21:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/30 18:26:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

/*
	@brief Verifie que tout entre le current et min tous on un index seperieure
	a current.
	@return 1 si c'est faux Vrai sinon.
	@param tete *t_mayon tete de la pile a
	@param min *t_mayon le mayon ayant le plus petit index.
	@param c *t_mayon le mayon qu'on shouaite compare.
*/
int	order(t_mayon *tete, t_mayon *min, t_mayon *c)
{
	t_mayon	*index;

	index = c;
	while (index != min)
	{
		if (c->index > index->index)
			return (1);
		if (index->next == NULL)
			index = tete;
		else
			index = index->next;
	}
	return (0);
}

/*
	@brief Permet de savoir si la pile a est trier. mais c'est la 2iem version,
	cette versione verifie que tout ce qui suit est plus grand et
	ce qui precedent plus petit
	@return Fonction qui return la position du plus petit element si trier.
	Sinon si elle n'est pas trier, la position du plus petit element en negatif - 1
	@param pils la structure pile.
	des lignes.
*/
int	pa_est_il_trier2(t_pile *pils)
{
	t_mayon	*current;
	t_mayon	*min;

	if (!pils || pils->a == NULL)
		return (0);
	min = find_min(pils->a);
	current = pils->a;
	while (current)
	{
		if (order(pils->a, min, current))
			return ((-1 * min->position) - 1);
		current = current->next;
	}
	return (min->position);
}

void	trie_5_ou_moin(t_pile *p)
{
	while (p->len_a > 3)
		use_instruction(1, p, 1, PB);
	p2_trie_p3(p, pa_est_il_trier2(p));
	while (p->b)
		add_into_pa(p, p->b);
	faire_r_ou_rr(p, find_min(p->a)->position, PILE_A);
}

/*
	@brief Prend un mayon b (on pars du principe qu'il est au sommet de la pile b)
	et l'ajoute correctement dans la pile a
	! Condition il faute que la pile a soit deja trier.
	@param p *t_pile contient toute ma pile pour efectuer des mouve.
	@param mayon_b *t_mayon le mayon b qu'on shouaite place.
	@return Ne return rien mais effectue des mouvement
*/
void	add_into_pa(t_pile *p, t_mayon *mayon_b)
{
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
