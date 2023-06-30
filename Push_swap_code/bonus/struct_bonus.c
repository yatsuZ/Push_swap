/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:52:42 by yzaoui            #+#    #+#             */
/*   Updated: 2023/06/22 16:34:09 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

/*
	@brief crée un node instruction.
	@param param *char il sagiras du parametre string ce sera une autre
	fonction qui interpretera la string.
	@return node instruction ou NULL en casde problème.
*/
t_node_instruction	*creat_node_instruction(char *param)
{
	t_node_instruction	*new_node;

	new_node = ft_calloc(1, sizeof(t_node_instruction));
	if (!new_node)
		return (NULL);
	new_node->param = param;
	new_node->instruction = -1;
	new_node->next = NULL;
	return (new_node);
}

/*
	@brief free toute les nodes instructions
	@return NULL
*/
t_node_instruction	*free_node_instruction(t_node_instruction **tete)
{
	if (!tete || !(*tete))
		return (NULL);
	free((*tete)->param);
	(*tete)->param = NULL;
	(*tete)->param = 0;
	free_node_instruction(&(*tete)->next);
	(*tete)->next = NULL;
	free(*tete);
	*tete = NULL;
	return (NULL);
}

/*
	@brief crée une liste d'instruction.
	@param tete *t_node_instruction la tete de la liste
	@return *t_list_instruction ou NULL en casde problème.
*/
t_list_instruction	*creat_list_instruction(t_node_instruction *tete)
{
	t_list_instruction	*new_list;
	t_node_instruction	*index;
	int					nbr;

	nbr = 0;
	index = tete;
	while (index)
	{
		index = index->next;
		nbr++;
	}
	new_list = ft_calloc(1, sizeof(t_list_instruction));
	if (new_list == NULL)
	{
		free_node_instruction(&tete);
		return (0);
	}
	new_list->all_instruction = tete;
	new_list->nbr_instruction = nbr;
	return (new_list);
}

/*
	@brief free la liste dinstruction
	@return NULL
*/
t_list_instruction	*free_list_instruction(t_list_instruction **tete)
{
	if (!tete || !(*tete))
		return (NULL);
	free_node_instruction(&((*tete)->all_instruction));
	(*tete)->all_instruction = NULL;
	(*tete)->nbr_instruction = 0;
	free(*tete);
	(*tete) = NULL;
	return (NULL);
}

int	read_param(t_node_instruction *noeud)
{
	int	len_param;
	int	index;

	len_param = 0;
	index = 0;
	while (noeud->param[len_param])
		len_param++;
	while (index < 11)
	{
		if (len_param == 4 && (index >= 2 && index <= 4))
		{
			if (!ft_strncmp(get_instruction(index), noeud->param, 5))
				return (noeud->instruction = index, 0);
		}
		else if (len_param == 3)
		{
			if (!ft_strncmp(get_instruction(index), noeud->param, 4))
				return (noeud->instruction = index, 0);
		}
		index++;
	}
	return (noeud->instruction = -2, 1);
}
