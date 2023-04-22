/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 15:29:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "Instruction/instruction.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef T_MAYON
#  define T_MAYON
/*
	@brief Cree la structur d'un mayon.
	@details Un mayon est un élément de la liste qui contient une valeur entière,
	un index, une position et des pointeurs vers le maillon suivant et précédent de la liste.
*/
typedef struct s_mayon
{
	int				val; // la data qu'il contient, qui est un int
	int				index; // son index par raport a sa valeur.
	int				position;// son index parraport son positionement dans la pile.
	struct s_mayon	*next; // pointeur du mayon suivant. NULL si c'est le dernier.
	struct s_mayon	*previous;// pointeur du mayon precedent. NULL si c'est le premier.
}	t_mayon;
#endif

# ifndef T_PILE
#  define T_PILE
/*
	@brief Cree la structur piles. Qui contiendra 2 chaine de mayon,
	la longuer de chaque mayon et la somme des 2
	@details piles est un élément qui contient 2 liste la longuer de chaque liste.
	et la somme total des longuer
*/
typedef struct s_pile
{
	struct s_mayon	*a;// liste A qui est une pile
	struct s_mayon	*b;// liste B qui est une pile
	int				len_a;// longuer de la pile A.
	int				len_b;// longuer de la pile B.
	int				len_total;// longuer de la pile A + B.
}	t_pile;
#endif

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
