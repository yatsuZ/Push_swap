/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_trie.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:17:48 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/27 16:30:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

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
		if ((next_m->index - m->index) > (current->index - m->index) \
		&& (current->index - m->index) >= 0)
			next_m = current;
		else if (m->index > next_m->index)
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
	ft_printf("next_ma->index = %d | mb->index= %d | \
	 precendent_ma->index = %d\n", \
	next_ma->index, mb->index, precendent_ma->index);
	ft_printf("res_n = %d et res_p=%d\n", res_n, res_p);
	if (precendent_ma->index < next_ma->index && res_p < res_n)
		return (res_p);
	return (res_n);
}

/*
	@brief implemente le coup rangement et rangement
*/
int	coup_rangement(t_pile *p, t_mayon *m)
{
	t_mayon	*next_m;

	next_m = find_this_next(p, m);
	m->rangement = suivie_rangement(next_m, m);
	return (cout_placement(next_m->position, p->len_a));
}
