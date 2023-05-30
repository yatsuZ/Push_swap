/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:59:08 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/27 18:50:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (*str == 0)
		return (0);
	else
		return (ft_printchar(*str) + ft_printstr(str + 1));
}
