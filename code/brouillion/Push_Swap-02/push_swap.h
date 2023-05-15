/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/15 21:55:28 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Constate
# define TRUE 1
# define FALSE 0
# define PILE_A 1
# define PILE_B 0
# define PA 0
# define PB 1
# define RRA 2
# define RRB 3
# define RRR 4
# define RA 5
# define RB 6
# define RR 7
# define SA 8
# define SB 9
# define SS 10

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

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction de Trie

int			validation_parfaitement_trier_pa(t_pile *pils, int position_min);
void		p2_trie_p3(t_pile *pil, int p_min);
void		trie_5_ou_moin(t_pile *p);
void		trie_generale(t_pile *pil);
int			cout_placement(int position, int len);
int			coup_rangement(t_pile *p, t_mayon *m);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction struct utile

void		adjusted_position(int decalage, t_mayon *pil);
t_mayon		*get_last_mayon(t_mayon *pil);
t_mayon		*find_index(t_pile *pils, int option);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Instructions

void		pa(t_pile *pils, int affichage);
void		pb(t_pile *pils, int affichage);
void		rra(t_pile *pils, int affichage);
void		rrb(t_pile *pils, int affichage);
void		rrr(t_pile *pils, int affichage);
void		ra(t_pile *pils, int affichage);
void		rb(t_pile *pils, int affichage);
void		rr(t_pile *pils, int affichage);
void		sa(t_pile *pils, int affichage);
void		sb(t_pile *pils, int affichage);
void		ss(t_pile *pils, int affichage);

void		use_instruction(int affichage, t_pile *pils, \
int nbr_instruction, ...);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Affichage

void		affichage_argc_argv(int z, int argc, char **argv);
void		affichage_mayon(t_mayon *m, int r);
void		affichage_pile(t_mayon *p);
void		affichage_struct_all(t_pile *s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Gestion message d'erreur

int			ft_atoi_verif(char *nptr);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour free

void		*free_struct(t_pile **p);
void		*free_pile(t_mayon **s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour Struct

t_mayon		*creat_mayon(int value, int position, t_mayon *previous);
void		ft_mayon_iter(t_mayon *mayon, int i, void (*f)(t_mayon *, int));
t_pile		*creat_struct(t_mayon *pile_a);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Parsing

t_mayon		*parsing(int z, int argc, char **argv, t_mayon *tete);

#endif
