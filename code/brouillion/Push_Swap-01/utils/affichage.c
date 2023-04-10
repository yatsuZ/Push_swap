/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/10 18:30:29 by yzaoui           ###   ########.fr       */
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

// Permet des reguler nombre d'espace et de print pour affichage_mayon
void	print_tab(int valeur, int option)
{
	if (option)
	{
		if (valeur < 10 && valeur > -1)
			ft_printf(" %d\t\t\t|", valeur);
		else if (valeur < 100 && valeur > -10)
			ft_printf(" %d\t\t|", valeur);
		else if (valeur <= -1000000000)
			ft_printf(" %d", valeur);
		else if (valeur <= -100000000 || valeur >= 1000000000)
			ft_printf(" %d|", valeur);
		else
			ft_printf(" %d\t|", valeur);
	}
	else
		ft_printf(" %d\t\t|", valeur);
}

// Affichage d'un mayon
// position	| pointeur	| valeur	| index	| previous	| next
void	affichage_mayon(t_mayon *m)
{
	if (!m)
		return ;
	ft_printf("\t|");
	print_tab(m->position, 1);
	ft_printf(" %p\t|", m);
	print_tab(m->val, 1);
	print_tab(m->index, 0);
	if (m->previous)
		ft_printf(" %p\t|", m->previous);
	else
		ft_printf(" %p\t\t|", m->previous);
	ft_printf(" %p\n", m->next);
	if (!(m->next))
		ft_printf("\t| -\t\t\t| -\t\t\t| -\t\t\t| -\t\t| -\t\t\t| -\n\n");
}

// Affiche toute la pile c'est a dire de chaque mayon
void	affichage_pile(t_mayon *p)
{
	ft_printf("Affichage de la pile :\n");
	if (!(p))
		return ((void) ft_printf("\t------- NULL ---------\n\n"));
	ft_printf("\t| position\t| pointeur\t| valeur\t| index\t| previous\t| next\n");
	ft_printf("\t| ----------|-----------|-----------\
|-------|-----------|------------\n");
	ft_mayon_iter(p, affichage_mayon);
}

/*
Affiche chaque contenue de la strucutre " t_pile "
pointeur contenue etc ...
*/
void	affichage_struct_all(t_pile *s)
{
	ft_printf("Affichage de toute la structure \"t_pile\":\n\n");
	if (!(s))
		return ((void) ft_printf("~~~~~~~ NULL ~~~~~~~\n"));
	ft_printf("Nombre de mayon total= %d\n\n", s->len_total);
	ft_printf("--------------------- PILE A :\n");
	affichage_pile(s->a);
	ft_printf("--------------------- PILE B :\n");
	affichage_pile(s->b);
}
