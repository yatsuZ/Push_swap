/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 17:04:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
TO DO :
	1. Cree une pile					| V 30/03/23
	2. Afficher les elements de la pile	| V 31/03/23
	3. Faire le parsing					| V 13/04/23
	4. Faire les fonction d'action		| V 17/04/23
	5. Teste les fonctions d'action		| V 22/04/23
	6. Algo pour 3 element				| X
	7. Algo pour 5 element				| X
	8. Algo pour plus de 10 elements	| X
	9. Verifier la norme, testeur, retirer fonction et commentaires inutile | X
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;

	a = parsing(0, argc, argv);
	if (error(0, a, 1))
		return (1);
	pils = creat_struct(a);
	if (error(0, pils, 1))
		return (1);
	free_struct(&pils);
	a = NULL;
	return (0);
}
