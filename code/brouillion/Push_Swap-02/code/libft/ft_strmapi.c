/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:02 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/17 17:16:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sc;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *) s);
	if (size > 4294967295)
		return (NULL);
	i = 0;
	sc = ft_calloc(++size, sizeof(char));
	if (!sc)
		return (NULL);
	while (s[i])
	{
		sc[i] = f((unsigned int)i, s[i]);
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
