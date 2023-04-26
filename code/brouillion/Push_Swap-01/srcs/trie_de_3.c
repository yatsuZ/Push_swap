/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_de_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:43:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/04/26 05:13:49 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief Fonction qui trie une pile de 3 element
	@param pil Structure pile, qui contient mes données et ma struct
	@param res_trie Int qui me dis si c'est trie ou non.
	Si negatife ce n'est pas trier.
	Si 0 Trier et chaque element est a sa place.
	Sinon dis a combien de case le plus petit mayon est decalée.
	@return Rien.
*/
void	trie_de_3_ou_moin(t_pile *pil, int res_trie)
{
	if (!pil || !res_trie)
		return ;
	if (pil->len_total == 2)
		return (use_instruction(1, pil, 1, 8));
}
