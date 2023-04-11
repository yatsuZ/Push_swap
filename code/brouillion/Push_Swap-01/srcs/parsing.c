/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/11 16:54:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Le fichier qui permet de verifier la validiter de argv
/*
TO DO:
	Anticiper les erreur d'argument, error syntax, non int.	V
	Ajouter au fur est a mesure les elements de la pile.	V
	Tout free en cas d'erreur.								X
	Rajouter le cas d'erreur de doublons.					X
Note -> en cas d'erreur tout free.
*/

// Return 1 si il y a 2 fois la meme valeur.
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
Le but du parsing et de lire les arguments
Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
l’invite de commande.
En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la
sortie d’erreur.
CAS d'erreur -> si certains paramètres ne sont pas des nombres, ne tiennent
pas dans un int, ou encore, s’il y a des doublons.

Si il y a rien en parametre la fonction retournera null .
Si les paramtre ne sont pas valide (ce nest pas un int ou erreur de syntax),
retournera null mais affichera "Error" suivi d’un ’\n’ sur la
sortie d’erreur et je free tout.
Sinon retourne la pile a
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
		{
			free_pile(&tete);
			return (0);
		}
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
