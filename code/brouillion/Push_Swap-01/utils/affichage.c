/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/13 17:07:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toutes les fonctions qui permetrons d'afficher en utilisant soit
// ft_printf() et write(). c'est plus un fichier d'outils pour debeuguer et
// afficher mes cas d'erreur.
// Note a moi meme : VERIFIER QU'IL Y AI BIEN QUE DES FT_PRINTF et pas de PRINTF

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Affichage general

/*
	@brief Affiche les nombre d'argument mis et le contenant.
	@param z est un index pour se deplacer dans argv metre a 0.
	@param argc Le nombre d'argument.
	@param argv tableau de string se sont les arguments.
	@return Ne return rien,
	Mais Print le nombre d'argument et Print chaque argument.
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

/*
	@brief Ajuste le nombre de tabulation par raport a une valeur pour l'afficher.
	@param valeur est un INT.
	@param option si different de 0 ajuste l'affichage sinon en mets juste 2.
	@return Ne return rien,
	Mais Print le nombre la valeur avec le nombre de tabulation qu'il lui faut
	suvie d'un "|".
*/
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
			ft_printf(" %d\t\t|", valeur);
	}
	else
		ft_printf(" %d\t\t|", valeur);
}

// @brief Affiche Tout les attributs d'un mayon.
// @param m pointeur d'un mayon.
// @returns m est un pointeur de la structure "t_mayon"
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

/*
	@brief Affiche TOUT les elements d'une pile
	@param p tete de la structure de la pile
	@returns Ne return rien, Afficher sous la forme d'un tableau tout
	les elements mayon du'une structure "t_mayon"
*/
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
	@brief Affiche chaque contenue de la strucutre " t_pile "
	@param s pointeur de la structure "t_pile"
	@returns Ne return rien. Mais affiche tout les elements
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
