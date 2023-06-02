/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:48:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/02 02:05:15 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./constante.h"
# include "./struct.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction de PreTrie

void		trie_median_min(t_pile *p, int median);
void		trie_median_max(t_pile *p, int sezieme);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction de Trie

int			pa_est_il_trier(t_pile *pils);
void		trie_moin_de_3(t_pile *pil, int p_min);
void		trie_moyen(t_pile *p);
void		trie_rapide(t_pile *pil);
void		faire_r_ou_rr(t_pile *p, int position, int ab);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction struct utile

void		adjusted_position(int decalage, t_mayon *pil);
t_mayon		*get_last_mayon(t_mayon *pil);
t_mayon		*find_min(t_mayon *tete);
t_mayon		*find_max(t_mayon *tete);
t_mayon		*find_most_close(t_mayon *tete_a, t_mayon *mayon_b);

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

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour free

void		*free_struct_pile(t_pile **p);
void		*free_lst_mayon(t_mayon **s);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Fonction pour Struct

t_mayon		*creat_mayon(int value, int position, t_mayon *previous);
void		ft_mayon_iter(t_mayon *mayon, int i, void (*f)(t_mayon *, int));
t_pile		*creat_struct(t_mayon *pile_a);

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Parsing

int			init_struct(t_pile **pils, int argc, char **argv);
t_mayon		*parsing(int z, int argc, char **argv, t_mayon *tete);

#endif
