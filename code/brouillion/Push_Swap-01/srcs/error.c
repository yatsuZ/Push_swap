/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 13:00:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toute les fonction qui gere les cas d'erreur.

int error(int id_verif, void *element)
{
	if (id_verif == 1)
	{
		id_verif = verication_de_pile_non_null(element);
	}
	return	(id_verif);
}

int verication_de_pile_non_null(t_pile_ab *p)
{
    if (p == NULL)
    {
        ft_printf();
    }	
}