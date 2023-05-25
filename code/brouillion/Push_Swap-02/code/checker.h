// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   checker.h                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/25 14:34:00 by yzaoui            #+#    #+#             */
// /*   Updated: 2023/05/25 15:34:01 by yzaoui           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef CHECKER_H
// # define CHECKER_H
// # include "libft/libft.h"
// # include <stdlib.h>
// # include <unistd.h>
// # include <stdarg.h>

// # define TRUE 1
// # define FALSE 0
// # define PILE_A 1
// # define PILE_B 0
// # define PA 0
// # define PB 1
// # define RRA 2
// # define RRB 3
// # define RRR 4
// # define RA 5
// # define RB 6
// # define RR 7
// # define SA 8
// # define SB 9
// # define SS 10

// typedef struct s_mayon
// {
// 	int				val;
// 	int				index;
// 	int				position;
// 	int				cplacement;
// 	int				crangement;
// 	int				rangement;
// 	int				trie;
// 	struct s_mayon	*next;
// 	struct s_mayon	*previous;
// }	t_mayon;

// typedef struct s_pile
// {
// 	struct s_mayon	*a;
// 	struct s_mayon	*b;
// 	int				len_a;
// 	int				len_b;
// 	int				len_total;
// }	t_pile;


// int			validation_parfaitement_trier_pa(t_pile *pils, int position_min);

// void		pa(t_pile *pils, int affichage);
// void		pb(t_pile *pils, int affichage);
// void		rra(t_pile *pils, int affichage);
// void		rrb(t_pile *pils, int affichage);
// void		rrr(t_pile *pils, int affichage);
// void		ra(t_pile *pils, int affichage);
// void		rb(t_pile *pils, int affichage);
// void		rr(t_pile *pils, int affichage);
// void		sa(t_pile *pils, int affichage);
// void		sb(t_pile *pils, int affichage);
// void		ss(t_pile *pils, int affichage);

// void		use_instruction(int affichage, t_pile *pils, \
// int nbr_instruction, ...);

// void		affichage_argc_argv(int z, int argc, char **argv);
// void		affichage_mayon(t_mayon *m, int r);
// void		affichage_pile(t_mayon *p);
// void		affichage_struct_all(t_pile *s);

// int			ft_atoi_verif(char *nptr);

// void		*free_struct(t_pile **p);
// void		*free_pile(t_mayon **s);

// t_mayon		*creat_mayon(int value, int position, t_mayon *previous);
// void		ft_mayon_iter(t_mayon *mayon, int i, void (*f)(t_mayon *, int));
// t_pile		*creat_struct(t_mayon *pile_a);

// t_mayon		*parsing(int z, int argc, char **argv, t_mayon *tete);

// #endif
