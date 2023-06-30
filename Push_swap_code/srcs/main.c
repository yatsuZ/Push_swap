/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/04 00:16:23 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

	if (argc == 1)
		return (0);
	if (init_struct(&pils, argc, argv))
		return (1);
	trie(pils);
	free_struct_pile(&pils);
	return (0);
}
