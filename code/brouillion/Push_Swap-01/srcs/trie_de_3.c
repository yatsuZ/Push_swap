/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_de_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:43:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/04/26 06:00:09 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cout_placement(int	position, int len)
{
	if (position > len / 2)
		return (position - len);
	return (position);
}

void faire_ra_ou_rra(t_pile *p, int p_min)
{
	int	res;

	res = cout_placement(p_min, p->len_a);
	while (res)
	{
		if (res < 0)
		{
			use_instruction(1, p, 1, 2);
			res++;
		}
		else
		{
			use_instruction(1, p, 1, 5);
			res--;
		}
	}
	
}

/*
	@brief Fonction qui trie + Range -> une pile de 2, 3 element ou une pile deja Trier.
	@param pil Structure pile, qui contient mes données et ma struct
	@param p_min Int qui me dis si c'est trie et ou est le mayon le plus petit
	ou non.
	Si negatife ce n'est pas trier.
	Sinon dis la position du plus petit mayon.
	@return Rien.
*/
void	P2_Trier_P3(t_pile *pil, int p_min)
{
	if (!pil || !p_min)
		return ;
	if (pil->len_total == 2)
		return (use_instruction(1, pil, 1, 8));
	if (p_min > 0)
		faire_ra_ou_rra(pil, p_min);
	
}
