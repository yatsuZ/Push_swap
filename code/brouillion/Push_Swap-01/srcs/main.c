/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/26 17:32:55 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
	@brief Fonction qui return 0 si la Pile A est totallement trier +
	Bien ranger.
	Si la pile est trier mais pas ranger. La position du plus petit noeud
	Sinon elle n'est pas trier. Parei que le precedent mais en Negatif - 1.
	@return en negatif la position du plus petit noeud - 1 si non trier.
	0 si trier et sans position_min ou pointeur NULL.
	Position du plus petit Noeud si trier mais decalage.
	@param pils la structure pile.
	@param position_min int metre position_min a 0 on pars du postulat
	que le plus petit est deja range. On le mets en param pour economiser
	des lignes.
*/
int	validation_de_trie(t_pile *pils, int position_min)
{
	int		i;
	t_mayon	*current;

	if (!pils || pils->a == NULL)
		return (0);
	if (pils->len_a != pils->len_total)
		return (-1);
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
	7.5 Corriger le fait quon peut metre des arguments+visualiseur| X
	8. Algo pour 5 element										  | X
	9. Algo pour plus de 10 elements							  | X
	10. Verifier la norme, testeur,
	retirer fonction et commentaires inutile					  | X
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;
	int		p_min;

	if (argc == 1)
		return (0);
	a = parsing(0, argc, argv);
	if (error(0, a, TRUE))
		return (1);
	pils = creat_struct(a);
	if (error(0, pils, TRUE))
		return (1);
	p_min = validation_de_trie(pils, 0);
	if (p_min > 0 || pils->len_total <= 3)
		p2_trie_p3(pils, p_min);
	else if (p_min)
		trie_generale(pils, p_min);
	free_struct(&pils);
	a = NULL;
	return (0);
}
