/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:16:07 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/28 18:58:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*cs1;
	char	*cs2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	cs1 = (char *) s1;
	cs2 = (char *) s2;
	i = 0;
	j = 0;
	s = ft_calloc(ft_strlen(cs1) + ft_strlen(cs2) + 1, sizeof(char));
	while (i < ft_strlen(cs1))
	{
		s[i] = cs1[i];
		i++;
	}
	while (j < ft_strlen(cs2))
	{
		s[j + i] = cs2[j];
		j++;
	}
	return (s);
}
