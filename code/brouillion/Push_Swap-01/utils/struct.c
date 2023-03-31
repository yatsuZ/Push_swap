/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 17:33:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// appliquer une fonction a tout les mayons d'un chaine.
void	ft_mayon_iter(t_mayon *mayon, void (*f)(t_mayon *))
{
	if (!mayon || !f)
		return ;
	f(mayon);
	if (!mayon->next)
		return ;
	ft_mayon_iter(mayon->next, f);
}

// calcule la longuer d'un mayon
int	ft_mayon_size(t_mayon *pile_a)
{
	if (!pile_a)
		return (0);
	return (1 + ft_mayon_size(pile_a->next));
}

// Fonction qui crée un mayon
t_mayon	*creat_mayon(int value, int position, t_mayon *previous)
{
	t_mayon	*new_mayon;

	new_mayon = ft_calloc(1, sizeof(t_mayon));
	new_mayon->val = value;
	new_mayon->index = 0;
	new_mayon->position = position;
	new_mayon->previous = previous;
	new_mayon->next = NULL;
	return (new_mayon);
}

// Fonction qui crée la structure de la pile a, b
t_pile	*creat_struct(t_mayon *pile_a)
{
	t_pile	*new_pil;
	int		len;

	len = ft_mayon_size(pile_a);
	new_pil = ft_calloc(1, sizeof(t_pile));
	new_pil->a = pile_a;
	new_pil->b = NULL;
	new_pil->len_a = len;
	new_pil->len_b = 0;
	new_pil->len_total = len;
	return (new_pil);
}
