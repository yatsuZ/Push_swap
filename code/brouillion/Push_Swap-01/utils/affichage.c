/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 18:28:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toutes les fonctions qui permetrons d'afficher des struc ou autre

// Refaire les fonction correctement

void	affichage_argc_argv(size_t z, int argc, char **argv)
{
	ft_printf("Nombre d'argument = %d\n", argc);
	ft_printf("-------------------\n");
	while (z < argc)
	{
		ft_printf("\tArgument %u = %s\n", z, argv[z]);
		z++;
	}
}

// affiche chaque contenue de la strucutre poitoneur valeur etc
// Refaire la fonction !!
void	affichage_struct(t_pile *p)
{
	ft_printf("Nombre d'argument = %d\n", p->len_total);
}
