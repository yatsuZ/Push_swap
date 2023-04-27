/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/04/27 17:05:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// creation de structure ou foncion utilise pour la mipulation de strucutre

/*
	@brief appliquer une fonction a tout les mayons d'un chaine.
	@param mayon pointeur de "t_mayon" qui est similaire a une liste chaine.
	@param f pointeur de fonction qui ne retourne rien mais qui prend en
	parametre pointeur de "t_mayon".
	@returns Rien
*/
void	ft_mayon_iter(t_mayon *mayon, int i, void (*f)(t_mayon *, int))
{
	if (!mayon || !f)
		return ;
	f(mayon, i);
	if (!mayon->next)
		return ;
	ft_mayon_iter(mayon->next, i, f);
}

/*
	@brief calcule la longuer d'un mayon.
	@param pile_a pointeur de "t_mayon" qui est similaire a une liste chaine.
	@return un int qui sera egale a la longeur pile
*/
int	ft_mayon_size(t_mayon *pile_a)
{
	if (!pile_a)
		return (0);
	return (1 + ft_mayon_size(pile_a->next));
}

/*
	@brief Ajutse l'index de chaque mayon par raport aux
	mayon actuel (qui est le dernier).
	et je parcours jusqu'aux premier mayon.
	Si la valeur du mayon current est superieur alors
	il est egal aux mayons precedent +1.
	Sinon le mayon precedent on lui rajoute +1.
	@param current pointeur de t_mayon correspond aux moyons actuel.
	@param precedent le mayon prdent.
	@return Rien pour linstant.
*/
void	put_index(t_mayon *previous, t_mayon *current)
{
	if (!previous)
		return ;
	if (previous->val > current->val)
		previous->index++;
	else if (previous->index >= current->index)
		current->index = previous->index + 1;
	put_index(previous->previous, current);
}

/*
	@brief Fonction qui crée un mayon
	@param value int qui sera egal a la valeur int du mayon qu'on cree.
	@param position int qui corepond a leur index dans la pile.
	@param previous corespond aux precedent pointeur.
	@return return un pointeur de "t_mayon".
*/
t_mayon	*creat_mayon(int value, int position, t_mayon *previous)
{
	t_mayon	*new_mayon;

	new_mayon = ft_calloc(1, sizeof(t_mayon));
	if (error(0, new_mayon, 1))
	{
		ft_printf("Dans la fonction \"creat_mayon\" \
la variable \"new_mayon\" est null.\n\n");
		return (0);
	}
	new_mayon->val = value;
	new_mayon->index = 0;
	new_mayon->trie = 0;
	new_mayon->cplacement = 0;
	new_mayon->crangement = 0;
	new_mayon->rangement = 0;
	new_mayon->position = position;
	new_mayon->previous = previous;
	new_mayon->next = 0;
	put_index(previous, new_mayon);
	return (new_mayon);
}

/*
	@brief Fonction qui crée un "t_pile"
	@param pile_a un pointeur de "t_mayon" et tete de mayon.
	@return return un pointeur de "t_pile".
*/
t_pile	*creat_struct(t_mayon *pile_a)
{
	t_pile	*new_pil;
	int		len;

	len = ft_mayon_size(pile_a);
	new_pil = ft_calloc(1, sizeof(t_pile));
	if (error(0, new_pil, TRUE))
	{
		ft_printf("Dans la fonction \"creat_struct\" \
la variable \"new_pil\" est null.\n\n");
		return (0);
	}
	new_pil->a = pile_a;
	new_pil->b = NULL;
	new_pil->len_a = len;
	new_pil->len_b = 0;
	new_pil->len_total = len;
	return (new_pil);
}
