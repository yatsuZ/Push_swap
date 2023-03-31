/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 13:36:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Fonction qui crée un mayon
t_mayon	*creat_mayon(int value, t_mayon *previous)
{
	t_mayon	*new_mayon;

	new_mayon = ft_calloc(1, sizeof(t_mayon));
	new_mayon->val = value;
	new_mayon->index = 0;
	new_mayon->position = 0;
	new_mayon->previous = previous;
	new_mayon->next = NULL;
	return (new_mayon);
}

// Fonction qui crée la pile a, b
t_pile	*creat_pil(void)
{
	t_pile	*new_pil;

	new_pil = ft_calloc(1, sizeof(t_pile));
	new_pil->a = NULL;
	new_pil->b = NULL;
	new_pil->len_a = 0;
	new_pil->len_b = 0;
	new_pil->len_total = 0;
	return (new_pil);
}
