/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/01 04:52:53 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./constante.h"
# include "./struct.h"
# include "./struct_bonus.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

t_mayon				*parsing(int z, int argc, char **argv, t_mayon *tete);
t_pile				*creat_struct(t_mayon *pile_a);
int					pa_est_il_trier(t_pile *pils);
void				*free_struct_pile(t_pile **p);
t_list_instruction	*parsing_instruction(void);
int					read_instructions(t_list_instruction *all_instruction);
t_node_instruction	*creat_node_instruction(char *param);
t_node_instruction	*free_node_instruction(t_node_instruction **tete);
t_list_instruction	*creat_list_instruction(t_node_instruction *tete);
t_list_instruction	*free_list_instruction(t_list_instruction **tete);
int					read_param(t_node_instruction *noeud);
void				use_instruction(int affichage, t_pile *pils, \
					int nbr_instruction, ...);
void				exec_instruction(t_node_instruction *instruction, \
					t_pile *pils);
int					init_struct(t_pile **pils, int argc, char **argv);

#endif
