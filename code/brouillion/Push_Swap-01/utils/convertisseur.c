/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:20:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/27 13:25:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Tout ce qui me permet de verifier la validiter de convertir un str en int.

// Verifie que val est compris dans les int si oui return 0
// sinon 2

/*
	@brief Prend un parametre un long et verfier qu'il peut etre caster en int.
	@param val_long long, la valeur que l'on veut verifier.
	@returns return 0 si il peut etre caster en INT,
	Sinon 2.
*/
int	verif_overflow(long val_long)
{
	int	val_int;

	val_int = (int) val_long;
	if (val_int != val_long)
		return (2);
	return (0);
}

/*
	@brief Fonction qui pertmet de savoir si une string peut etre convertie en int.
	On verifie la syntax, sa valeur qu'il sagit bien d'un int.
	@param nptr string, la string qu'on verifie si peut transformer en int.
	@return Return 0 si on peut le transformer en int sinon 1 si erreur de syntax,
	2 si problème d'overflow.
*/
int	ft_atoi_verif(char *nptr)
{
	long	nbr;
	int		signe;
	size_t	i;

	i = 0;
	nbr = 0;
	signe = 1;
	if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] == '0' && nptr[i + 1] != '\0')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0')
		return (1);
	return (verif_overflow(signe * nbr));
}

// Verifier que le pointeur peut etre convertie en int
// si oui retourne 0 sinon 1.

/*
	@brief Gere le cas d'erreur si le pointeur ne peut pas etre
	convertie en int.
	@param p pointeur void, qu'on vas caster en string.
	@param affichage si different de 0 alors on affiche un message
	d'erreur si il y a une erreur.
	@returns return 1 si p ne peut pas etre transformer en int, 0 si
	il peut l'etre.
*/
int	id_error_2(void *p, int affichage)
{
	int	retour;

	retour = ft_atoi_verif((char *)p);
	if (affichage && retour)
		return (print_text_error(retour + 2), 1);
	return (0);
}
