/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/23 19:24:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fichier principal qui execute le code

/*
	@brief Fonction qui return 0 si la Pile A est totallement trier +
	Bien ranger.
	-1 si la pile A n'est pas complete ou qu'elle n'est pas trier.
	ou autre chose si la pile est trier mais pas ranger
	@return -1 si non trier ou pile a non complete.
	0 si trier et sans decallage ou pointeur NULL.
	X si trier mais decalage.
	@param pils la structure pile.
	@param decallage int metre decallage a 0 cest pour economise des lignes.
*/
int	validation_de_trie(t_pile *pils, int decallage)
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
				decallage = current->position;
				i = 0;
			}
			else
				return (-1);
		}
		i++;
		current = current->next;
	}
	return (decallage);
}

	// ft_printf("\nLe mayon le plus petit : \n");
	// affichage_mayon(find_index(pils, 0));
	// ft_printf("\nLe mayon Median : \n");
	// affichage_mayon(find_index(pils, 1));
	// ft_printf("\nLe mayon Le plus grand : \n");
	// affichage_mayon(find_index(pils, 2));

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
	7. Algo pour 3 element										  | X
	8. Algo pour 5 element										  | X
	9. Algo pour plus de 10 elements							  | X
	10. Verifier la norme, testeur,
	retirer fonction et commentaires inutile					  | X
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;
	int		res;

	a = parsing(0, argc, argv);
	if (error(0, a, 1))
		return (1);
	pils = creat_struct(a);
	if (error(0, pils, 1))
		return (1);
	res = validation_de_trie(pils, 0);
	if (!res)
		ft_printf("\nVVVV La Pile est Parfaitement ranger trier : ");
	else if (res == -1)
		ft_printf("\nXXXX C'est pas trier : ");
	else
		ft_printf("\n~~~~~La Pile est trier.\n\
Mais le plus petit element a un decalage de %d element : ", res);
	affichage_struct_all(pils);
	free_struct(&pils);
	a = NULL;
	return (0);
}
