/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:26:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/22 16:55:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Centraliser tout les actione plus afficher leur actions ilsseront tous
// dans un tableau.

/* Verifier que les instruction marche check liste :
	1. Si on leur donne un pointeur null (cas aui n'est pas sensé arriver)
	qu'il ne se passe rien. CHECK
	2. Verifier que les fonction fais ce qu'on leur demande et
	verifier pas de problème de leak.
*/

// @brief Tableau de mes fonctions d'instruction.
static void (*const	g_instruction[])(t_pile *pils) = {
	&pa,
	&pb,
	&rra,
	&rrb,
	&rrr,
	&ra,
	&rb,
	&rr,
	&sa,
	&sb,
	&ss
};

// @brief Tableau de mes fonctions d'instruction, Test.
static void (*const	g_test_instruction[])(t_pile *pils) = {
	&tpa,
	&tpb,
	&trra,
	&trrb,
	&trrr,
	&tra,
	&trb,
	&trr,
	&tsa,
	&tsb,
	&tss
};

// fonction qui verifie que chaque fonction marche
void	test_instruction(int f, t_pile *pils)
{
	if (f > 10 || f < 0)
		ft_printf("f = %d. f doit etre compris entre 0 et 10.\n", f);
	else
		g_test_instruction[f](pils);
	affichage_struct_all(pils);
}

void	use_instruction(int f, t_pile *pils)
{
	if (f > 10 || f < 0)
	{
		ft_printf("f = %d. f doit etre compris entre 0 et 10.\n", f);
		return ;
	}
	g_instruction[f](pils);
}
