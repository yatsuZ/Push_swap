/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:07:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/30 14:39:15 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
	@brief Cherche dans la tete d'un mayon le plus petit element.
	@param tete du mayon du coup soi a ou b.
	@return le mayon le plus petit
*/
t_mayon	*find_min(t_mayon *tete)
{
	t_mayon	*index;
	t_mayon	*res;

	index = tete;
	res = tete;
	while (index)
	{
		if (index->index < res->index)
			res = index;
		if (res->index == 0)
			return (res);
		index = index->next;
	}
	return (res);
}

/*
	@brief Cherche dans la tete d'un mayon le plus grand element.
	@param tete du mayon du coup soi a ou b.
	@return le mayon le plus ayant la plus grande valeur.
*/
t_mayon	*find_max(t_mayon *tete)
{
	t_mayon	*index;
	t_mayon	*res;

	index = tete;
	res = tete;
	while (index)
	{
		if (index->index > res->index)
			res = index;
		index = index->next;
	}
	return (res);
}

/*
	@brief Nous cherchons le mayon le plus proche
	mis en parametre celui qui le suit le plus proche.
	va compare chaque index et prendra la diff la plus petite.
	@param tete_a *t_mayon tete de la pile a.
	@param mayon_b *t_mayon le mayon de de reference.
	@return return le mayon dans la pile
*/
t_mayon	*find_most_close(t_mayon *tete_a, t_mayon *mayon_b)
{
	t_mayon	*res;
	int		diff_index;
	int		buff;
	t_mayon	*index;

	index = tete_a;
	diff_index = 0;
	while (index)
	{
		if (mayon_b->index > index->index)
			buff = mayon_b->index - index->index;
		else
			buff = index->index - mayon_b->index;
		if (!diff_index || buff < diff_index)
		{
			res = index;
			diff_index = buff;
		}
		index = index->next;
	}
	return (res);
}
