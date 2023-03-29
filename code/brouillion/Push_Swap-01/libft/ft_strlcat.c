/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:08:54 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/27 17:09:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	if (!dest || !src)
		return (0);
	i = 0;
	srclen = ft_strlen((char *)src);
	destlen = ft_strlen(dest);
	if (destlen < size)
		srclen = srclen + destlen;
	else
		srclen = srclen + size;
	if (size > 0 && !(size <= destlen))
	{
		while (src[i] && (i + destlen) < size - 1)
		{
			dest[i + destlen] = src[i];
			i++;
		}
		dest[i + destlen] = '\0';
	}
	return (srclen);
}
