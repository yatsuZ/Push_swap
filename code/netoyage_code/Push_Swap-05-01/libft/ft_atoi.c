/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:12:02 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/03 23:55:08 by yatsu            ###   ########.fr       */
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
		if (nbr > 2147483647 || nbr * signe < -2147483648)
			return (0);
		i++;
	}
	return ((int)(signe * nbr));
}
