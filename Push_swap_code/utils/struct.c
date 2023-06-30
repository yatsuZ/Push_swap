/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:18:33 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// JE GARDE LE FICHIER

#include "../header/push_swap.h"
#include "../header/checker.h"

void	ft_mayon_iter(t_mayon *mayon, int i, void (*f)(t_mayon *, int))
{
	if (!mayon || !f)
		return ;
	f(mayon, i);
	if (!mayon->next)
		return ;
	ft_mayon_iter(mayon->next, i, f);
}

int	ft_mayon_size(t_mayon *pile_a)
{
	if (!pile_a)
		return (0);
	return (1 + ft_mayon_size(pile_a->next));
}

void	put_index(t_mayon *previous, t_mayon *current)
{
	if (!previous)
		return ;
	if (previous->val > current->val)
		previous->index++;
	else if (previous->index >= current->index)
		current->index = previous->index + 1;
	put_index(previous->previous, current);
}

t_mayon	*creat_mayon(int value, int position, t_mayon *previous)
{
	t_mayon	*new_mayon;

	new_mayon = ft_calloc(1, sizeof(t_mayon));
	if (new_mayon == NULL)
		return (0);
	new_mayon->val = value;
	new_mayon->index = 0;
	new_mayon->position = position;
	new_mayon->previous = previous;
	new_mayon->next = 0;
	put_index(previous, new_mayon);
	return (new_mayon);
}

t_pile	*creat_struct(t_mayon *pile_a)
{
	t_pile	*new_pil;
	int		len;

	len = ft_mayon_size(pile_a);
	new_pil = ft_calloc(1, sizeof(t_pile));
	if (new_pil == NULL)
		return (free_lst_mayon(&pile_a));
	new_pil->a = pile_a;
	new_pil->b = NULL;
	new_pil->len_a = len;
	new_pil->len_b = 0;
	new_pil->len_total = len;
	return (new_pil);
}
