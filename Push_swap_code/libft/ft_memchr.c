/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:48:26 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/14 14:04:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;
	unsigned char	e;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	m = (unsigned char *)s;
	e = (unsigned char)c;
	while (i < n)
	{
		if (m[i] == e)
			return (m + i);
		i++;
	}
	return (NULL);
}
