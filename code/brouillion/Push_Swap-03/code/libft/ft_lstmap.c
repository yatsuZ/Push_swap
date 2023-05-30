/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:00:32 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/24 19:13:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;

	if (!lst || !f || !del)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	if (!l->content)
	{
		ft_lstdelone(l, del);
		free(l);
		l = NULL;
		return (NULL);
	}
	if (!lst->next)
		return (l);
	l->next = ft_lstmap(lst->next, f, del);
	if (!l->next)
	{
		ft_lstdelone(l, del);
		free(l);
		l = NULL;
	}
	return (l);
}
