/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/16 16:31:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
	@brief Permet de savoir si la pile a est trier.
	@return Fonction qui return la position du plus petit element si trier.
	Sinon si elle n'est pas trier, la position du plus petit element en negatif - 1
	@param pils la structure pile.
	@param position_min int init a 0 mis en param pour economiser
	des lignes.
*/
int	pa_est_il_trier(t_pile *pils, int position_min)
{
	int		i;
	t_mayon	*current;

	if (!pils || pils->a == NULL)
		return (0);
	i = pils->a->index;
	current = pils->a;
	while (current)
	{
		if (i != current->index)
		{
			if (current->index == 0)
			{
				position_min = current->position;
				i = 0;
			}
			else
				return ((-1 * find_index(pils, 0)->position) - 1);
		}
		i++;
		current = current->next;
	}
	return (position_min);
}

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
	8. Algo pour 5 element										  | X
	9. Algo pour plus de 10 elements							  | X
	10. Verifier la norme, testeur,
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
		ft_printf("\n\nERORRE PAS FINI\n\n\n");
	free_struct(&pils);
	a = NULL;
	return (0);
}
