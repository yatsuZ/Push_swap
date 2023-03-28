/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:09:22 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/27 18:48:15 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrofchar(long n, size_t size)
{
	size++;
	if (n < 0)
		size = ft_nbrofchar(-n, size);
	else if (n >= 10)
		size = ft_nbrofchar(n / 10, size);
	return (size);
}

static size_t	ft_add(long n, char *s, size_t i)
{
	if (n < 0)
	{
		s[i] = '-';
		i = ft_add(-n, s, ++i);
	}
	else if (n >= 10)
	{
		i = ft_add(n / 10, s, i);
		s[i] = (char)(n % 10) + 48;
	}
	else
	{
		s[i] = (char)(n % 10) + 48;
	}
	return (++i);
}

char	*ft_itoa(int n)
{
	size_t	nbrofchar;
	char	*strint;

	nbrofchar = ft_nbrofchar((long)n, 0) + 1;
	strint = ft_calloc(nbrofchar, sizeof(char));
	ft_add((long)n, strint, 0);
	return (strint);
}
