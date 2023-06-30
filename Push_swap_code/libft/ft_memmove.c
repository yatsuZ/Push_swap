/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:21:41 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/15 12:02:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long	i;
	char	*d;
	char	*s;

	if (!dest || !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	if (!(d >= s && d <= s + n))
	{
		ft_memcpy(d, s, n);
	}
	else
	{
		i = n - 1;
		while (d[i] && i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
