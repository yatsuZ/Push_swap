/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:43:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/27 21:24:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

/*
	@brief Recupere tout les parametre mis dans l'entrée une en utilisant gnl.
	@return la structure de list_instruction, le nombre d'instruction,
	leur position et leur parametre en string.
*/
t_list_instruction	*parsing_instruction(void)
{
	t_node_instruction	*tete;
	t_node_instruction	*index;
	char				*res;

	res = get_next_line(1);
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
		res = get_next_line(1);
	}
	return (free(res), creat_list_instruction(tete));
}

/*
	@brief Verifie que les instuction son correcte.
	Si le cas je precise quel instuction il sagi.
	@return 0 si tout est bon 0 sinon
*/
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

/*
	@brief jexecute toute les actions. sur la pile
	@param tete node_instruction la tete de toute
	les isntructions que je dois faire.
	@param pils t_pils contient ma pile.
	@return rien.
*/
void	exec_instruction(t_node_instruction *instruction, t_pile *pils)
{
	while (instruction)
	{
		use_instruction(0, pils, 1, instruction->instruction);
		instruction = instruction->next;
	}
	if (pa_est_il_trier(pils, 0) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
