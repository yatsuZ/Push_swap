/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:33:05 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:18:23 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// JE GARDE LE FICHIER

#include "../header/push_swap.h"
#include "../header/checker.h"

void	*free_lst_mayon(t_mayon **s)
{
	if (!s || !(*s))
		return (NULL);
	(*s)->index = 0;
	(*s)->position = 0;
	(*s)->val = 0;
	(*s)->previous = NULL;
	free_lst_mayon(&(*s)->next);
	(*s)->next = NULL;
	free(*s);
	*s = NULL;
	return (NULL);
}

void	*free_struct_pile(t_pile **p)
{
	if (!p || !(*p))
		return (NULL);
	free_lst_mayon(&((*p)->a));
	(*p)->a = NULL;
	free_lst_mayon(&((*p)->b));
	(*p)->b = NULL;
	(*p)->len_a = 0;
	(*p)->len_b = 0;
	(*p)->len_total = 0;
	free(*p);
	*p = NULL;
	return (NULL);
}
