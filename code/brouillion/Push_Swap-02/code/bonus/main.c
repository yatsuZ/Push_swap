/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:34:03 by yzaoui            #+#    #+#             */
/*   Updated: 2023/05/25 15:20:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TO DO :
	1. Faire le parsing											| X
	2. Cree une liste de structure qui contient une instruction | X

	Comment lire les parametres en entre 1 ? -> Il doit ensuite attendre et lire des instructions sur l’entrée standard. | ?

	3. Lire toute les instruction puis stock quelque pars		| X
	4. Faire les execution de commande lue en param				| X
	3. Faire la fin, Verifie que tout es bon					| X
*/
/*
	@brief Ve
*/
int	main(int argc, char **argv)
{
	t_pile	*pils;
	t_mayon	*a;

	// parsing
	a = parsing(0, argc, argv, NULL);
	if (a == NULL)
		return (1);
	pils = creat_struct(a);
	if (pils == NULL)
		return (1);
	// lire lentrée avoir une liste dinstruction

	// Les executer

	// Voir si c'est trier + FIN
	if (pa_est_il_trier(pils, 0) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_struct(&pils);
	a = NULL;
	return (0);
}
