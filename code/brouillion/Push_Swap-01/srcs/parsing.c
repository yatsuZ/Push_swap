/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/10 19:15:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Le fichier qui permet de verifier la validiter de argv

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
	t_mayon	*a;
	t_mayon *precend;

	if (argc == 1)
		return (0);
	ft_printf("Il y a des arguments.\n");
	precend = 0;
	while ((z + 1)< argc)
	{
		z++;
		ft_printf("%d -> %s\n", z, argv[z]);
	}
	return (0);
}
