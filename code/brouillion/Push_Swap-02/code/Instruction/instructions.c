/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:26:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/29 19:14:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../header/checker.h"

// Centraliser tout les actione plus afficher leur actions ilsseront tous
// dans un tableau.

/* Verifier que les instruction marche check liste :
	1. Si on leur donne un pointeur null (cas aui n'est pas sensé arriver)
	qu'il ne se passe rien. CHECK
	2. Verifier que les fonction fais ce qu'on leur demande et
	verifier pas de problème de leak.
*/

// @brief Tableau de mes fonctions d'instruction.
static void (*const	g_instruction[])(t_pile *pils, int affichage) = {
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

/*
	@brief Fonction qui fais plusieur instruction.
	@param affichage Si different de 0 affiche le message "pa"
	etc...
	@param pils structure pile.
	@param nbr_instruction dire le nombre dinstruction qui suit tres important.
	@param ... suite de nombre entre 0 et 10 pour chaque commande.
	@return rien juste il execute les instruction mis en parametre a la suite.
*/
void	use_instruction(int affichage, t_pile *pils, int nbr_instruction, ...)
{
	va_list	all_instruction;

	va_start(all_instruction, nbr_instruction);
	while (nbr_instruction--)
	{
		g_instruction[va_arg(all_instruction, int)](pils, affichage);
	}
}

/*
	@param pils structure de la pile.
	@param option int.
	Si 0 cherche le plus petit index.
	Si 1 cherche la medianne.
	Si 2 cherche le plus grand index.
	@brief permet de chercher l'index 0, median, le plus grnand dans la pile A.
	@return Return NULL si la len
	est inferieurre a 2 ou pointeur NULL.
*/
t_mayon	*find_index(t_pile *pils, int option)
{
	t_mayon	*current;
	int		median;

	if (pils == NULL || pils->len_total <= 2)
		return (NULL);
	median = (pils->len_total - 1) / 2;
	current = pils->a;
	while (current)
	{
		if (option == 0 && current->index == 0)
			return (current);
		else if (option == 1 && current->index == median)
			return (current);
		else if (option == 2 && current->index == (pils->len_total - 1))
			return (current);
		current = current->next;
	}
	return (NULL);
}
