/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:00:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/27 17:56:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_node_instruction
{
	char						*param;
	int							instruction;
	struct s_node_instruction	*next;
}	t_node_instruction;

typedef struct s_list_instruction
{
	struct s_node_instruction	*all_instruction;
	int							nbr_instruction ;
}	t_list_instruction;

#endif
