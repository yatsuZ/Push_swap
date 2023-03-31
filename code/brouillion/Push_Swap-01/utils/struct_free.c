/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:33:05 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 17:41:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// free une lise de mayon,
// (une pile) a partir de la tete
void	free_pile(t_mayon **s)
{
	if (!s || !(*s))
		return ;
	(*s)->index = 0;
	(*s)->position = 0;
	(*s)->val = 0;
	(*s)->previous = NULL;
	free_pile(&(*s)->next);
	(*s)->next = NULL;
	free(*s);
	*s = NULL;
}

// free la structure t_pile de a a z
void	free_struct(t_pile **p)
{
	if (!p || !(*p))
		return ;
	free_pile(&((*p)->a));
	free_pile(&((*p)->b));
	(*p)->len_a = 0;
	(*p)->len_b = 0;
	(*p)->len_total = 0;
	free(*p);
}
