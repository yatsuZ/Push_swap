/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:20:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/15 20:59:32 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Tout ce qui me permet de verifier la validiter de convertir un str en int.

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
