/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:12:02 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 15:24:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	nbr;
	int		signe;
	size_t	i;

	i = 0;
	nbr = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
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
	return ((int)(signe * nbr));
}
