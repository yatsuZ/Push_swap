/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:38:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/30 18:20:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toutes les fonctions qui permetrons d'afficher en utilisant soit
// ft_printf() et write().
// Note a moi meme : VERIFIER QU'IL Y AI BIEN QUE DES FT_PRINTF et pas de PRINTF

// Refaire les fonction correctement

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Affichage general

/*
Affiche les nombre d'argument mis et le contenant.
*/
void	affichage_argc_argv(size_t z, int argc, char **argv)
{
	ft_printf("Nombre d'argument = %d\n", argc);
	ft_printf("-------------------\n");
	while (z < argc)
	{
		ft_printf("\tArgument %u = %s\n", z, argv[z]);
		z++;
	}
}

// Refaire la fonction !!
/*
Affiche chaque contenue de la strucutre " t_pile "
pointeur contenue etc ...
*/
void	affichage_struct(t_pile *p)
{
	ft_printf("Nombre d'argument = %d\n", p->len_total);
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Pour les Erreurs

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
