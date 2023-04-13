/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/13 17:38:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toute les fonction qui gere les cas d'erreur.

/*
	@brief Verifie qu'un pointeur n'est pas NULL.
	@param p pointeur void, ce qu'on shouaite verifer.
	@param affichage si diffrente de 0 on affiche les message d'erreur.
	@returns return 1 en cas d'erreur sinon 0.
*/
int	id_error_0(void *p, int affichage)
{
	if (p != NULL)
		return (0);
	if (affichage)
	{
		print_text_error(0);
		ft_printf("Voici l'adresse du pointeur -> %p\n", p);
	}
	return (1);
}

/*
	@brief return 1 quoi qu'il arrive ignore les parametres.
	@param p pointeur void.
	@param affichage ne sert a rien.
	@returns return 1.
*/
int	id_error_1(void *p, int affichage)
{
	(void) p;
	(void) affichage;
	return (1);
}

// @brief Tableau de mes fonction error.
static int (*const	g_verif_error[])(void *p, int affichage) = {
	&id_error_0,
	&id_error_1,
	&id_error_2
};

/*
	@brief La fonction qui controlle les gestions d'erreurs.
	@param id_verif int, correpond a une fonction dans le tableau
	"g_verif_error".
	@param element pointeur void, qui est un pouteur
	qu'on prend n parametre pour les fonctions.
	@param affichage si diffrente de 0 on affiche les message d'erreur.
	@return retourne le retour de la fonction utilise.
*/
int	error(int id_verif, void *element, int affichage)
{
	id_verif = g_verif_error[id_verif](element, affichage);
	return (id_verif);
}
