/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/30 15:21:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

/*
	@brief return le nombre de bit aue possede le plus grand index
	@param tete t_mayon la tete d'une pile que se soit a ou b.
	@return le nombre de bit que possede le plus grand index
*/
static	int	get_max_bits(t_mayon *tete)
{
	int		max;
	int		max_bits;

	max = find_max(tete)->index;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	trie_generale(t_pile *p)
{
	t_mayon	*temp;
	int		i;
	int		j;
	int		max_bits;
	int		size;

	i = 0;
	temp = p->a;
	max_bits = get_max_bits(p->a);
	size = p->len_a;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp = p->a;
			if (((temp->index >> i) & 1) == 1)
				use_instruction(TRUE, p, 1, RA);
			else
				use_instruction(TRUE, p, 1, PB);
		}
		while (p->b)
			use_instruction(TRUE, p, 1, PA);
		i++;
	}
}
