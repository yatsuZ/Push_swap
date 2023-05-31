/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:27:43 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 16:58:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && (size > 0 && i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i++] = '\0';
	}
	return (ft_strlen((char *)src));
}
