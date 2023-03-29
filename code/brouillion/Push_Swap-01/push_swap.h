/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/29 18:31:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Cree la structur d'un mayon
typedef struct s_mayon
{
	int				val;
	size_t			index;
	size_t			position;
	struct s_mayon	*next;
	struct s_mayon	*previous;
}	t_mayon;

// Cree la structur contenant les 2 pile
typedef struct s_pile
{
	struct s_mayon	*a;
	struct s_mayon	*b;
	size_t			len_a;
	size_t			len_b;
	size_t			len_total;
}	t_pile;

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Affichage

void		affichage_argc_argv(size_t z, int argc, char **argv);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Cas d'erreur

int			error(int id_verif, void *element);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Parsing

t_mayon		*parsing(size_t i, int argc, char **argv);

#endif