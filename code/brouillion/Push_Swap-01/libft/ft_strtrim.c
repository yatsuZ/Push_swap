/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:56:27 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/21 18:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

//return 0 si il y a "a" dans "s"
static int	ft_cstrcmp(char a, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!a || a == s[i++])
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;
	size_t			i;
	char			*s;

	if (!s1)
		return (NULL);
	i = 0;
	s = (char *) s1;
	while (s1[i] && !ft_cstrcmp(s[i], (char *) set))
		i++;
	start = i;
	i = ft_strlen(s);
	while (i > start && !ft_cstrcmp((char)s1[i], (char *) set))
		i--;
	len = i + 1;
	if (start >= len)
		return (NULL);
	else
	{
		s = ft_substr(s1, start, len - start);
		if (!s)
			return (NULL);
		return (s);
	}
}
