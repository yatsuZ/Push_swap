/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 15:43:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toutes les fonctions qui permetrons d'afficher en utilisant soit
// ft_printf() et write().
// Note a moi meme : VERIFIER QU'IL Y AI BIEN QUE DES FT_PRINTF et pas de PRINTF

// Refaire les fonction correctement

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Affichage general

/*
Affiche les nombre d'argument mis et le contenant.
*/
void	affichage_argc_argv(int z, int argc, char **argv)
{
	ft_printf("Nombre d'argument = %d\n", argc);
	ft_printf("-------------------\n");
	while (z < argc)
	{
		ft_printf("\tArgument %u = %s\n", z, argv[z]);
		z++;
	}
}

// Refaire la fonction !!

// Affichage d'un mayon
// position	| pointeur	| valeur	| index	| previous	| next
void	affichage_mayon(t_mayon *m)
{
	if (m)
	{
		ft_printf("\t%d\t| %p\t| %d\t| %d\t| %p\t| %p\n", m->position, m, m->val, \
		m->index, m->previous, m->next);
	}
	else
		ft_printf("\t-\t| -\t| -\t| -\t| -\t| -\t\n\n");
}

// Affiche toute la pile c'est a dire de chaque mayon
void	affichage_pile(t_mayon *p)
{
	ft_printf("Affichage de toute une pile :\n");
	if (!(p))
		return (ft_printf("------- NULL ---------"), void);
	ft_printf("\tposition\t| pointeur\t| valeur\t| index\t| previous\t| next");
	ft_lstiter(p, &affichage_mayon);
}

/*
Affiche chaque contenue de la strucutre " t_pile "
pointeur contenue etc ...
*/
void	affichage_struct_all(t_pile *s)
{
	ft_printf("Affichage de toute la structure \"t_pile\":\n");
	if (!(s))
		return (ft_printf("~~~~~~~ NULL ~~~~~~~\n"));
	ft_printf("Nombre de mayon total= %d\n", s->len_total);
	ft_printf("--------------------- Affichage de la pile A :\n");
	affichage_pile(s->a);
	ft_printf("--------------------- Affichage de la pile B :\n");
	affichage_pile(s->b);
}
