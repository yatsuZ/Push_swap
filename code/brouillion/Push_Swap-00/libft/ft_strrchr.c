/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:53:17 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 16:09:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (!ft_isascii(c))
		return ((char *)s);
	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char *) s + i);
	return (NULL);
}
