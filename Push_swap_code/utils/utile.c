/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:07:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/22 16:25:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FONCTION UTILE POUR LE TRIE

#include "../header/push_swap.h"

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

int	init_struct(t_pile **pils, int argc, char **argv)
{
	t_mayon	*a;

	a = parsing(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	(*pils) = creat_struct(a);
	if ((*pils) == NULL)
		return (1);
	return (0);
}
