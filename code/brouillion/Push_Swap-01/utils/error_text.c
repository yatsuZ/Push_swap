/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:18:20 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/11 16:45:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Gestionde message d'erreur.

// Tableau contenant tout mes message d'erreur
static const char	*g_text_error[] = {
	"ID error 0 : Un malloc n'a pas fonctione\n",
	NULL,
	"ID error 2 : Argument Invalide dans le parsing.\n",
	"ID error 3 : Erreur Syntax. Un caractere n'est pas un nombre, Ou \
Vous avez mis un 0 suivie d'autre caractere ce qui est une syntax non \
permise.\n",
	"ID error 4 : Overflow la valeur n'est pas compris dans les int\n",
	"ID error 5 : Erreur il y a deux fois la meme valeur dans les arguments.\
\n"
};

// Affiche "Error\n" sur la sortie d'erreur
void	print_error_endl(void)
{
	write(2, "Error\n", 6);
}

/*
En fonction d'id_error j'affiche son text correspondent
Cas Particulier entre 2 et 4 compris qui affiche "Error\n" sur la sortie d'erreur
*/
void	print_text_error(int id_error)
{
	if (id_error >= 2 && id_error <= 5)
		print_error_endl();
	if (id_error >= 3 && id_error <= 5)
		ft_printf(g_text_error[2]);
	ft_printf(g_text_error[id_error]);
}
