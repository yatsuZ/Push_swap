/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/11 15:15:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
I.faire un code parsing qui verifie que argv et valide et retourne un maillion.

		1. Cree une pile					| V 30/03/23
		2. Afficher les elements de la pile	| V 31/03/23
		3. Faire le parsing					| X

int	main(int argc, char **argv)
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;

	a = parsing(0, argc, argv);
	if (error(0, a, 1))
		return (1);
	ft_printf("\n\nFIN ->\n");
	affichage_pile(a);
	pils = creat_struct(a);
	free_struct(&pils);
	return (0);
}
