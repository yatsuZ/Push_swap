/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:59:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 03:54:20 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/checker.h"

static int	verif_overflow(long val_long)
{
	int	val_int;

	val_int = (int) val_long;
	if (val_int != val_long)
		return (2);
	return (0);
}

static int	ft_atoi_verif(char *nptr)
{
	long	nbr;
	int		signe;
	size_t	i;

	i = 0;
	nbr = 0;
	signe = 1;
	if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] == '0' && nptr[i + 1] != '\0')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		i++;
	}
	if (nptr[i] != '\0')
		return (1);
	return (verif_overflow(signe * nbr));
}

static int	error_parsing(char *arg, int val, t_mayon *last_m, int index)
{
	if (ft_atoi_verif(arg) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (index == 0)
		return (0);
	else if (last_m == NULL)
		return (1);
	else if (last_m->val == val)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	index--;
	return (error_parsing(arg, val, last_m->previous, index));
}

t_mayon	*parsing(int z, int argc, char **argv, t_mayon *tete)
{
	t_mayon	*last_m;
	int		new_val;

	if (argc == 1)
		return (0);
	last_m = 0;
	while ((z + 1) < argc)
	{
		z++;
		new_val = ft_atoi(argv[z]);
		if (error_parsing(argv[z], new_val, last_m, z - 1))
			return (free_lst_mayon(&tete));
		if (!tete)
		{
			last_m = creat_mayon(new_val, (z - 1), 0);
			tete = last_m;
		}
		else
		{
			last_m->next = creat_mayon(new_val, (z - 1), last_m);
			last_m = last_m->next;
		}
	}
	return (tete);
}
