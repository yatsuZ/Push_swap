/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/13 19:02:00 by yzaoui           ###   ########.fr       */
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
	@brief Verifier qu'il n'y a pas 2 fois la meme valeur dans la structure
	"t_mayon". La fonction marche en recursif.
	@param val la valeur que l'ont doit verifier dans la structure.
	@param tete la tete de ma structure "t_mayon"
	@returns Return 0 Si la tete est null est vide ou que la valeur n'a pas etais
	trouver dans la structure.
	Sinon affiche un message d'erreur et return 1 si la valeur est trouver.
*/
int	no_double(int val, t_mayon *tete)
{
	if (!tete)
		return (0);
	if (val == tete->val)
	{
		print_text_error(5);
		return (1);
	}
	return (no_double(val, tete->next));
}

/*
	@brief La fonction "parsing" lit les arguments passés en entrée et renvoie
	une pile de valeurs.
	@param z: entier, valeur initiale pour le parcours des arguments inialise
	a 0.
	@param argc: entier, nombre d'arguments passés en entrée.
	@param argv: tableau de chaînes de caractères, arguments passés en entrée.
	@returns un pointeur vers la tête de la pile si les arguments sont valides,
	NULL sinon
	Si aucun argument n'est fourni, la fonction retourne NULL.
	Si les arguments ne sont pas valides (par exemple, s'ils ne sont pas des
	entiers ou s'il y a deux fois la même valeur),
	la fonction renvoie NULL mais affiche un message d'erreur sur la sortie
	d'erreur.
*/
t_mayon	*parsing(int z, int argc, char **argv)
{
	t_mayon	*tete;
	t_mayon	*index;
	int		new_val;

	if (argc == 1)
		return (0);
	tete = 0;
	while ((z + 1) < argc)
	{
		z++;
		new_val = ft_atoi(argv[z]);
		if (error(2, argv[z], 1) || no_double(new_val, tete))
			return (free_pile(&tete));
		if (!tete)
		{
			index = creat_mayon(new_val, (z - 1), 0);
			tete = index;
		}
		else
		{
			index->next = creat_mayon(new_val, (z - 1), index);
			index = index->next;
		}
	}
	return (tete);
}
