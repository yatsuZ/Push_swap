/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:29:34 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/31 13:40:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Toute les fonction qui gere les cas d'erreur.

// Verifie que le malloc a bien etais fais
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

// Ne retourne que 1
int	id_error_1(void *p, int affichage)
{
	(void) p;
	(void) affichage;
	return (1);
}

// Tableau de toute mes fonction error.
static int (*const	g_verif_error[])(void *p, int affichage) = {
	&id_error_0,
	&id_error_1
};

/*
La fonction qui controlle toute les gestion d'erreur.
id_verif	= Quelle test va effectuer la fonction
element		= Si la fonction doit prendre un parametre en compte
affichage	= 1 affiche un message, 0 n'affiche rien
*/
int	error(int id_verif, void *element, int affichage)
{
	id_verif = g_verif_error[id_verif](element, affichage);
	return (id_verif);
}
