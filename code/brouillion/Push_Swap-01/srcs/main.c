/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/17 19:22:23 by yzaoui           ###   ########.fr       */
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
	5. Teste les fonctions d'action		| X
	6. Algo pour 5 element				| X
	7. Algo pour plus de 10 elements	| X
	8. Verifier la norme les testeur et retirer les commentaires inutile | X
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
	{
		ft_printf("La fonction \"creat_struct\" a flop dans le main.\n\n");
		return (1);
	}
	affichage_struct_all(pils);
	ft_printf("-\n-\nPUSH B --------------\n\n");
	pb(pils);
	affichage_struct_all(pils);
	ft_printf("-\n-\nPUSH B --------------\n\n");
	pb(pils);
	affichage_struct_all(pils);
	ft_printf("-\n-\nPUSH B --------------\n\n");
	pb(pils);
	affichage_struct_all(pils);
	free_struct(&pils);
	a = NULL;
	return (0);
}
