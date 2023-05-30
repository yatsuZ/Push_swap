/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:03:21 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/25 11:34:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nomber_of_word(const char *s, char c)
{
	size_t	nbw;
	size_t	i;
	int		boolean;

	boolean = 1;
	i = 0;
	nbw = 0;
	while (s[i])
	{
		if (s[i] == c)
			boolean = 1;
		else
		{
			if (boolean)
				nbw++;
			boolean = 0;
		}
		i++;
	}
	return (nbw);
}

static char	**ft_cutsplit(size_t i, size_t nbw, const char *s, char c)
{
	size_t	j;
	char	**tab;

	tab = ft_calloc(nbw, sizeof(char *));
	j = 1;
	nbw = 0;
	while (s[i] && tab)
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				while (s[i] && s[i] != c)
					i++;
				tab[nbw] = ft_substr(s, j, i-- - j);
				nbw++;
			}
			j = 0;
		}
		i++;
	}
	return (tab);
}

static int	ft_secure(size_t j, const char *s, char c, size_t i)
{
	char	*sec;

	while (s[i])
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				while (s[i] && s[i] != 0)
					i++;
				sec = ft_substr(s, j, i-- - j);
				if (!sec)
					return (0);
				free(sec);
			}
			j = 0;
		}
		i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	nbw;
	char	**tab;

	if (!s)
		return (NULL);
	nbw = ft_nomber_of_word(s, c);
	if (ft_secure(1, s, c, 0) == 0)
		return (NULL);
	tab = ft_cutsplit(0, 1 + nbw, s, c);
	if (!tab)
		return (NULL);
	tab[nbw] = NULL;
	return (tab);
}
