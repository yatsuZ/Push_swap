/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_trie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:39 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/29 22:31:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include "../../header/checker.h"

/*
	@brief Permet de savoir si la pile a est trier.
	@return Fonction qui return la position du plus petit element si trier.
	Sinon si elle n'est pas trier, la position du plus petit element en negatif - 1
	@param pils la structure pile.
	@param position_min int init a 0 mis en param pour economiser
	des lignes.
*/
int	pa_est_il_trier(t_pile *pils, int position_min)
{
	int		i;
	t_mayon	*current;

	if (!pils || pils->a == NULL)
		return (0);
	i = pils->a->index;
	current = pils->a;
	while (current)
	{
		if (i != current->index)
		{
			if (current->index == find_min(pils->a)->index)
			{
				position_min = current->position;
				i = 0;
			}
			else
				return ((-1 * find_min(pils->a)->position) - 1);
		}
		i++;
		current = current->next;
	}
	return (position_min);
}