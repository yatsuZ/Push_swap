/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 12:53:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

int	main(int argc, char **argv)
{
	t_pile_ab	*pile;

	pile = cheker(0, argc, argv);
	if (error(1, pile))
		return (1);
	ft_printf("Pile n'est pas NULL\n----------------------\n");
	affichage_struct(0, pile);
	return (0);
}
