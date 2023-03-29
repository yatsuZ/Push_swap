/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 12:57:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toutes les fonctions qui permetrons d'afficher des struc ou autre
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

void	affichage_struct(size_t z, t_pile_ab *p)
{
	ft_printf("Nombre d'argument = %d\n", p->len);
	ft_printf("Seperateur index = %d\n", p->seperateur);
	ft_printf("Element du tableau de la pile : \n");
	while (z < p->len)
	{
		ft_printf("\tp->tab[ %d ] = %d\n", z, p->tab[z]);
		z++;
	}
}

void	affichage_pile_a(size_t z, t_pile_ab *p)
{
    
}