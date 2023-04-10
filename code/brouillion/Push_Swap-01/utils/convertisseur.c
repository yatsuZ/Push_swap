/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:20:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/10 19:52:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// Verifier que le pointeur peut etre convertie en int
// si oui retourne 0 sinon 1.
int	id_error_2(void *p, int affichage)
{
	int	retour;

	retour = ft_atoi_verif((const char *) p);
	if (affichage && retour)
	{
		print_text_error(2);
		print_text_error(retour + 2);
		return (1);
	}
	return (0);
}

// Verifie que val est compirs dans les int si oui return 0
// sinon 2
int	verif_overflow(long val)
{

}

/*
Verifie que la string commence par un signe puis verifie
qu'il n'y a que des nombres sinon retourne 1 puis verifie que la valeur
est un int.
*/
int	ft_atoi_verif(const char *nptr)
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
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0')
		return (1);
	return verif_overflow(signe * nbr);
}
