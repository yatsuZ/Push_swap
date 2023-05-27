/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_5_ou_moin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:21:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/05/27 16:31:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	trie_5_ou_moin(t_pile *p)
{
	if (p->len_total == 4)
		ft_printf("Trie de 4\n");
	else
		ft_printf("Trie de 5\n");
	affichage_struct_all(p);
	return ;
}
