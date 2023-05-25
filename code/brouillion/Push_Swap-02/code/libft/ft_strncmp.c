/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:39:06 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/25 16:20:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0 && (!s1[i] || !s2[i]))
		return (0);
	while (s1[i] && i < n)
	{
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
		if (r != 0)
			return (r);
	}
	r = 0;
	if (i != n)
		r = s1[i] - s2[i];
	return (r);
}
