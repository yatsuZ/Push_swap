/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 15:42:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
I.faire un code parsing qui verifie que argv et valide et retourne un maillion.

		1. Cree une pile					| V 30/03/23
		2. Afficher les elements de la pile	| X

int	main(int argc, char **argv)
*/
int	main(int argc, char **argv)
{
	t_pile	*pil;

	pil = creat_pil();
	if (error(0, pil, 1))
		return (printf("qweqweqwe"), 1);
	parsing(0, argc, argv);
	return (0);
}