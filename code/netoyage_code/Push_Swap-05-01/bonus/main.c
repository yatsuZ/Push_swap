/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:03 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/04 00:16:03 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	main(int argc, char **argv)
{
	t_pile				*pils;
	t_list_instruction	*all_instruction;

	if (init_struct(&pils, argc, argv))
		return (1);
	all_instruction = parsing_instruction();
	if (!all_instruction)
		return (free_struct_pile(&pils), \
		free_list_instruction(&all_instruction), 1);
	if (read_instructions(all_instruction))
		return (free_struct_pile(&pils), \
		free_list_instruction(&all_instruction), write(2, "Error\n", 6), 0);
	exec_instruction(all_instruction->all_instruction, pils);
	free_list_instruction(&all_instruction);
	free_struct_pile(&pils);
	return (0);
}
