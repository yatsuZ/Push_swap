/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:37:09 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 15:28:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H
# include "../push_swap.h"

# ifndef T_MAYON
#  define T_MAYON
typedef struct s_mayon
{
	int				val;
	int				index;
	int				position;
	struct s_mayon	*next;
	struct s_mayon	*previous;
}	t_mayon;
# endif

# ifndef T_PILE
#  define T_PILE
typedef struct s_pile
{
	struct s_mayon	*a;
	struct s_mayon	*b;
	int				len_a;
	int				len_b;
	int				len_total;
}	t_pile;
# endif

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

// Fonction de test ->

void	test(int f, t_pile *pils);

#endif
