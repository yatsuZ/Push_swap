/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 18:31:16 by yzaoui           ###   ########.fr       */
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
	t_pile	*pil;
	t_mayon	*test;

	(void) argc;
	(void) argv;
	test = creat_mayon(-2147483647, 0, NULL);
	test->next = creat_mayon(3, 1, test);
	pil = creat_struct(test);
	if (error(0, pil, 1))
		return (1);
	affichage_struct_all(pil);
	free_struct(&pil);
	return (0);
}
