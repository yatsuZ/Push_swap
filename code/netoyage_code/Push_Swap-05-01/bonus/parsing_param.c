/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/22 16:34:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

t_list_instruction	*parsing_instruction(void)
{
	t_node_instruction	*tete;
	t_node_instruction	*index;
	char				*res;

	res = get_next_line(0);
	tete = NULL;
	index = NULL;
	while (res)
	{
		if (!tete)
		{
			tete = creat_node_instruction(res);
			index = tete;
		}
		else
		{
			index->next = creat_node_instruction(res);
			index = index->next;
		}
		if (!index)
			return (free_node_instruction(&tete), free(res), NULL);
		res = get_next_line(0);
	}
	return (free(res), creat_list_instruction(tete));
}

int	read_instructions(t_list_instruction *all_instruction)
{
	t_node_instruction	*index;

	if (!all_instruction)
		return (1);
	index = all_instruction->all_instruction;
	while (index)
	{
		if (read_param(index))
			return (1);
		index = index->next;
	}
	return (0);
}

void	exec_instruction(t_node_instruction *instruction, t_pile *pils)
{
	while (instruction)
	{
		use_instruction(0, pils, 1, instruction->instruction);
		instruction = instruction->next;
	}
	if (pa_est_il_trier(pils) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

char	*get_instruction(int instruction_id)
{
	if (instruction_id == 0)
		return ("pa\n");
	else if (instruction_id == 1)
		return ("pb\n");
	else if (instruction_id == 2)
		return ("rra\n");
	else if (instruction_id == 3)
		return ("rrb\n");
	else if (instruction_id == 4)
		return ("rrr\n");
	else if (instruction_id == 5)
		return ("ra\n");
	else if (instruction_id == 6)
		return ("rb\n");
	else if (instruction_id == 7)
		return ("rr\n");
	else if (instruction_id == 8)
		return ("sa\n");
	else if (instruction_id == 9)
		return ("sb\n");
	else if (instruction_id == 10)
		return ("ss\n");
	return (NULL);
}
