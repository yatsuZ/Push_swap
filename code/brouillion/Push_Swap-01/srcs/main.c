/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/17 14:26:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
I.faire un code parsing qui verifie que argv et valide et retourne un maillion.

		1. Cree une pile					| V 30/03/23
		2. Afficher les elements de la pile	| V 31/03/23
		3. Faire le parsing					| V 13/04/23
		4. Faire les fonction d'action		| X

int	main(int argc, char **argv)
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;
	t_mayon	*b;

	a = parsing(0, argc, argv);
	if (error(0, a, 1))
		return (1);
	ft_printf("\n\nFIN ->\n");
	// affichage_pile(a);
	b = creat_mayon(50, 0, 0);
	b->next =creat_mayon(-50, 1, b);
	pils = creat_struct(a);
	pils->b = b;
	pils->len_b = pils->len_b + 2;
	affichage_struct_all(pils);
	push_a(pils);
	ft_printf("\n\n------------- PUSH A :\n\n");
	affichage_struct_all(pils);
	push_a(pils);
	ft_printf("\n\n------------- PUSH A :\n\n");
	affichage_struct_all(pils);
	free_struct(&pils);
	a = NULL;
	return (0);
}

// verifier tout les malloc / calloc verifier et corriger anticiper
// les cas d'erreur
