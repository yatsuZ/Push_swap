/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_trie.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:17:48 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/27 19:54:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	@brief un mayon de pile b cherche le mayon qui lui suit dans la pile a
	@return le mayon qui suis le mayon de la pile le plus proche.
*/
t_mayon	*find_this_next(t_pile *p, t_mayon *m)
{
	t_mayon	*next_m;
	t_mayon	*current;

	next_m = p->a;
	current = next_m;
	while (current)
	{
		if (current->index > m->index && next_m->index < current->index)
			next_m = current;
		current = current->next;
	}
	return (next_m);
}

/*
	@brief Dis si mb suit ou et suivie du mayon precedent de next ma.
	@return la diffrence de l'index de mb et de lindex le plus proche dans
	la pile a.
*/
int	suivie_rangement(t_mayon *next_ma, t_mayon *mb)
{
	t_mayon	*precendent_ma;
	int		res_p;
	int		res_n;

	if (next_ma->previous == NULL)
		precendent_ma = get_last_mayon(next_ma);
	else
		precendent_ma = next_ma->previous;
	res_n = next_ma->index - mb->index;
	res_p = mb->index - precendent_ma->index;
	if (res_p < res_n)
		return (res_p);
	return (res_n);
}

int	coup_rangement(t_pile *p, t_mayon *m)
{
	t_mayon	*next_m;

	next_m = find_this_next(p, m);
// Regarde si a combien sa le suit.

// calculer le cout de r rra qu'il faudra faire
}
