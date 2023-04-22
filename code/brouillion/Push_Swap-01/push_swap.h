/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 16:53:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

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

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction struct utile

void		adjusted_position(int decalage, t_mayon *pil);
t_mayon		*get_last_mayon(t_mayon *pil);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Instructions

void		pa(t_pile *pils);
void		pb(t_pile *pils);
void		rra(t_pile *pils);
void		rrb(t_pile *pils);
void		rrr(t_pile *pils);
void		ra(t_pile *pils);
void		rb(t_pile *pils);
void		rr(t_pile *pils);
void		sa(t_pile *pils);
void		sb(t_pile *pils);
void		ss(t_pile *pils);

void		use_instruction(int f, t_pile *pils);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- TEST des Instructions

void		tpa(t_pile *pils);
void		tpb(t_pile *pils);
void		trra(t_pile *pils);
void		trrb(t_pile *pils);
void		trrr(t_pile *pils);
void		tra(t_pile *pils);
void		trb(t_pile *pils);
void		trr(t_pile *pils);
void		tsa(t_pile *pils);
void		tsb(t_pile *pils);
void		tss(t_pile *pils);

// Fonction de test d'instruction->

void		test_instruction(int f, t_pile *pils);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Affichage

void		affichage_argc_argv(int z, int argc, char **argv);
void		affichage_mayon(t_mayon *m);
void		affichage_pile(t_mayon *p);
void		affichage_struct_all(t_pile *s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Gestion message d'erreur

int			id_error_2(void *p, int affichage);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Gestion message d'erreur

void		print_text_error(int id_error);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Cas d'erreur

int			error(int id_verif, void *element, int affichage);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour free

void		*free_struct(t_pile **p);
void		*free_pile(t_mayon **s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour Struct

t_mayon		*creat_mayon(int value, int position, t_mayon *previous);
void		ft_mayon_iter(t_mayon *mayon, void (*f)(t_mayon *));
t_pile		*creat_struct(t_mayon *pile_a);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Parsing

t_mayon		*parsing(int z, int argc, char **argv);

#endif
