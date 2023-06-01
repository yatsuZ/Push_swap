/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/31 23:14:06 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// fichier principal qui execute le code

/*
TO DO :
	1. Cree une pile											  | V 30/03/23
	2. Afficher les elements de la pile							  | V 31/03/23
	3. Faire le parsing											  | V 13/04/23
	4. Faire les fonction d'action								  | V 17/04/23
	5. Teste les fonctions d'action								  | V 22/04/23
	6. Faire une fonction qui me valide si toute la pile est trie,
	trier est ranger ou non.
	Recuper le plus grand petit dindex et median.				  | V 23/04/23
	6.5 Faire que je peux metre une liste dinstruction + affichage| V 26/04/23
	7. Algo pour 3 element										  | V 26/04/23
	8. Algo pour 5 element										  | V 29/04/23
	9. Algo pour plus de 5 elements								  | X
	10. Verifier la norme puis ranger mes fonction code
	header surpimer ce que je nutilise pas testeur,
	retirer fonction et commentaires inutile					  | X
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;
	int		trie_res;

	a = parsing(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	pils = creat_struct(a);
	if (pils == NULL)
		return (1);
	trie_res = pa_est_il_trier(pils, 0);
	if (trie_res > 0 || pils->len_total <= 3)
		p2_trie_p3(pils, trie_res);
	else if (trie_res && pils->len_total <= 5)
		trie_5_ou_moin(pils);
	else if (trie_res)
		trie_generale(pils);
	if (pa_est_il_trier(pils, 0) != 0)
		ft_printf("CE n'est pas trier \n\n");
	free_struct(&pils);
	a = NULL;
	return (0);
}
