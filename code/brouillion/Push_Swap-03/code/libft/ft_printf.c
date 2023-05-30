/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:09:21 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/27 18:50:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//pas besoin de mettre un break vue que jai un return qui tope la fonction
int	ft_findtype(const char *str, unsigned long i, va_list tab)
{
	if (str[i] == 'c')
		return (ft_printchar((char) va_arg(tab, int)));
	else if (str[i] == 's')
		return (ft_printstr(va_arg(tab, char *)));
	else if (str[i] == '%')
		return (ft_printchar('%'));
	else if (str[i] == 'i' || str[i] == 'd')
		return (ft_prnbr((long)va_arg(tab, int), "0123456789", 10));
	else if (str[i] == 'u')
		return (ft_prexa(va_arg(tab, unsigned int), "0123456789", 10));
	else if (str[i] == 'x')
		return (ft_prexa(va_arg(tab, unsigned int), "0123456789abcdef", 16));
	else if (str[i] == 'X')
		return (ft_prexa(va_arg(tab, unsigned int), "0123456789ABCDEF", 16));
	else if (str[i] == 'p')
		return (ft_printptr(va_arg(tab, void *)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list			tab;
	unsigned long	i;
	int				nbrc;

	va_start(tab, str);
	nbrc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			nbrc += ft_findtype(str, ++i, tab);
		else
			nbrc += ft_printchar(str[i]);
		i++;
	}
	va_end(tab);
	return (nbrc);
}
