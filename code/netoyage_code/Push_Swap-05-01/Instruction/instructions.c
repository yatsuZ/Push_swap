/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:26:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/22 16:26:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/checker.h"

static void	find_instruction(int instruction_id, int affichage, t_pile *pils)
{
	if (instruction_id == 0)
		pa(pils, affichage);
	else if (instruction_id == 1)
		pb(pils, affichage);
	else if (instruction_id == 2)
		rra(pils, affichage);
	else if (instruction_id == 3)
		rrb(pils, affichage);
	else if (instruction_id == 4)
		rrr(pils, affichage);
	else if (instruction_id == 5)
		ra(pils, affichage);
	else if (instruction_id == 6)
		rb(pils, affichage);
	else if (instruction_id == 7)
		rr(pils, affichage);
	else if (instruction_id == 8)
		sa(pils, affichage);
	else if (instruction_id == 9)
		sb(pils, affichage);
	else if (instruction_id == 10)
		ss(pils, affichage);
}

void	use_instruction(int affichage, t_pile *pils, int nbr_instruction, ...)
{
	va_list	all_instruction;

	va_start(all_instruction, nbr_instruction);
	while (nbr_instruction--)
		find_instruction(va_arg(all_instruction, int), affichage, pils);
	va_end(all_instruction);
}

void	adjusted_position(int decalage, t_mayon *pil)
{
	if (!pil)
		return ;
	pil->position = pil->position + decalage;
	adjusted_position(decalage, pil->next);
}

t_mayon	*get_last_mayon(t_mayon *pil)
{
	if (!pil)
		return (0);
	else if (pil->next == 0)
		return (pil);
	return (get_last_mayon(pil->next));
}
