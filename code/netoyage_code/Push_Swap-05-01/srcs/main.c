/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:12:21 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	init_struct(t_pile **pils, int argc, char **argv)
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

static void	trie(t_pile *pils)
{
	int		trie_res;

	trie_res = pa_est_il_trier(pils);
	if (trie_res > 0 || pils->len_total <= 3)
		trie_moin_de_3(pils, trie_res);
	else if (trie_res && pils->len_total <= 25)
		trie_moyen(pils);
	else if (trie_res)
		trie_rapide(pils);
}

int	main(int argc, char **argv)
{
	t_pile	*pils;

	if (init_struct(&pils, argc, argv))
		return (1);
	trie(pils);
	free_struct_pile(&pils);
	return (0);
}
