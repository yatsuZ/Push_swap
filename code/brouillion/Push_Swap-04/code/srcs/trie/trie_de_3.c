/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_de_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:43:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/29 22:51:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

// @param position -> int de la position du mayon
// @param len -> la longuer de la pile
// @return un int positive ou negatife si negatife il faut utilise des rr.
int	cout_placement(int position, int len)
{
	if (position > len / 2)
		return (position - len);
	return (position);
}

// @brief Fais le choix le plus optimal entre ra et rra
// @param p -> la pile
// @param ab si 0 choisi la pile B sinon A
// @param position position de l'element
void	faire_r_ou_rr(t_pile *p, int position, int ab)
{
	int	res;

	if (ab)
		res = cout_placement(position, p->len_a);
	else
		res = cout_placement(position, p->len_a);
	while (res)
	{
		if (res < 0)
		{
			if (ab)
				use_instruction(TRUE, p, 1, RRA);
			else
				use_instruction(TRUE, p, 1, RRB);
			res++;
		}
		else
		{
			if (ab)
				use_instruction(TRUE, p, 1, RA);
			else
				use_instruction(TRUE, p, 1, RB);
			res--;
		}
	}
}

/*
	@brief Fonction qui trie + Range -> une pile de 2, 3 element ou,
	une pile deja Trier.
	@param pil Structure pile, qui contient mes données et ma struct
	@param p_min Int qui me dis si c'est trie et ou est le mayon le plus petit
	ou non.
	Si negatife ce n'est pas trier. alors le metre en positive et faire - 1
	Sinon dis la position du plus petit mayon.
	@return Rien.
*/
void	p2_trie_p3(t_pile *pil, int p_min)
{
	if (!pil || !p_min)
		return ;
	if (pil->len_total == 2 || (pil->len_a == 3 && p_min == -2))
		return (use_instruction(TRUE, pil, 1, SA));
	else if (pil->len_a == 3 && p_min == -3)
		return (use_instruction(TRUE, pil, 2, RA, SA));
	else if (pil->len_a == 3 && p_min == -1)
		return (use_instruction(TRUE, pil, 2, RRA, SA));
	else if (p_min > 0)
		return (faire_r_ou_rr(pil, p_min, PILE_A));
}
