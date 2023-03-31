/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:18:20 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 15:19:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Gestionde message d'erreur.

static const char	*g_text_error[] = {
	"ID error 0 : Un malloc n'a pas fonctione\n",
	NULL,
	"ID error 2 : Argument Invalide dans le parsing"
};

// Affiche "Error\n" sur la sortie d'erreur
void	print_error_endl(void)
{
	write(2, "Error\n", 5);
}

/*
En fonction d'id_error j'affiche son text correspondent
Cas Particulier pour -1 qui affiche "Error\n" sur la sotie d'erreur
*/
void	print_text_error(int id_error)
{
	if (id_error == 2)
		print_error_endl();
	ft_printf(g_text_error[id_error]);
}
