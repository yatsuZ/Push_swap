/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:03 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/27 21:24:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

/*
TO DO :
	1. Faire le parsing											| V 2023/05/27
	2. Cree une liste de structure qui contient une instruction | V 2023/05/27

	Comment lire les parametres en entre 1 ? -> Il doit ensuite attendre et
	lire des instructions sur l’entrée standard. | utilise gnl et pour fd 1

	3. Lire toute les instruction puis stock quelque pars		| V 2023/05/27
	4. Faire les execution de commande lue en param				| V 2023/05/27
	3. Faire la fin, Verifie que tout es bon					| V 2023/05/27
*/

/*
	@brief Verifie que la liste dinstruction est trie la pile correctement.
*/
int	main(int argc, char **argv)
{
	t_pile				*pils;
	t_list_instruction	*all_instruction;
	t_mayon				*a;

	a = parsing(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	pils = creat_struct(a);
	if (pils == NULL)
		return (1);
	all_instruction = parsing_instruction();
	if (!all_instruction)
		return (free_struct(&pils), free_list_instruction(&all_instruction), 1);
	if (read_instructions(all_instruction))
		return (free_struct(&pils), free_list_instruction(&all_instruction), \
		write(2, "Error\n", 6), 0);
	exec_instruction(all_instruction->all_instruction, pils);
	free_list_instruction(&all_instruction);
	free_struct(&pils);
	a = NULL;
	return (0);
}
