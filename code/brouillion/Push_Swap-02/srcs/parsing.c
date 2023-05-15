/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/15 21:56:54 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Le fichier qui permet de verifier la validiter des arguments
/*
TO DO:
	Anticiper les erreur d'argument, error syntax, non int.	V
	Ajouter au fur est a mesure les elements de la pile.	V
	Tout free en cas d'erreur.								V
	Rajouter le cas d'erreur de doublons.					V
	Norminette												V
	ajouter un fonction qui ajoute les index
Parsing FINI.
*/

/*
	@brief verifier premierement que le argv est corecte en terme de parametre
	puis
	puis on verifier qu'il n'as pas deja val dans la la pile
	@param arg: string qui a permis davoir "val" on doit verifier
	qu'il n'y as pas derreur d'entre de param.
	@param val: c'est "arg" converti avec mon atoi on verifiera qu'on
	auras pas 2 fois la meme valeur.
	@param last_m: dernier mayon crée c'est pour voir qu'il n'est pas null
	et à partir du dernier mayon on peut avoir le premier mayon.
	@param index: sel'index de la boucle j'en aurais besoin car si
	il est egale à 0 c'est normal que lastmayon est null.
	@return 1 en cas de problème sinon 0
*/
int	error_parsing(char *arg, int val, t_mayon *last_m, int index)
{
	if (ft_atoi_verif(arg) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_m == NULL)
		return (1);
	else if (last_m->val == val)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (error_parsing(arg, val, last_m->previous, index));
}

/*
	@brief La fonction "parsing" lit les arguments passés en entrée et renvoie
	une pile de valeurs. De ma structure t_mayon.
	@param z: entier, valeur initiale pour le parcours des arguments inialise
	a 0. permet deconomiser des lignes
	@param argc: entier, nombre d'arguments passés en entrée.
	@param argv: tableau de chaînes de caractères, arguments passés en entrée.
	@param tete: initilise a NULL c'est pour economiser des lignes.
	@returns un pointeur vers la tête de la pile si les arguments sont valides,
	NULL sinon
	Si aucun argument n'est fourni, la fonction retourne NULL.
	Si les arguments ne sont pas valides (par exemple, s'ils ne sont pas des
	entiers ou s'il y a deux fois la même valeur),
	la fonction renvoie NULL mais affiche un message d'erreur sur la sortie
	d'erreur.
*/
t_mayon	*parsing(int z, int argc, char **argv, t_mayon *tete)
{
	t_mayon	*last_m;
	int		new_val;

	if (argc == 1)
		return (0);
	last_m = 0;
	while ((z + 1) < argc)
	{
		z++;
		new_val = ft_atoi(argv[z]);
		if (error_parsing(argv[z], new_val, last_m, z - 1))
			return (free_pile(&tete));
		if (!tete)
		{
			last_m = creat_mayon(new_val, (z - 1), 0);
			tete = last_m;
		}
		else
		{
			last_m->next = creat_mayon(new_val, (z - 1), last_m);
			last_m = last_m->next;
		}
	}
	return (tete);
}
