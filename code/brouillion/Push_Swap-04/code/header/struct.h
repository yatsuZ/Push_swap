/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:22:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/27 16:24:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
	@brief Cree la structur d'un mayon.
	@details Un mayon est un élément de la liste qui contient une
	valeur entière,
	un index, une position et des pointeurs vers le maillon suivant
	et précédent de la liste.
*/
typedef struct s_mayon
{
	int				val;
	int				index;
	int				position;
	int				cplacement;
	int				crangement;
	int				rangement;
	int				trie;
	struct s_mayon	*next;
	struct s_mayon	*previous;
}	t_mayon;

typedef struct s_pile
{
	struct s_mayon	*a;
	struct s_mayon	*b;
	int				len_a;
	int				len_b;
	int				len_total;
}	t_pile;

#endif
