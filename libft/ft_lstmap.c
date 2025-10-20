/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:25:19 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/09 16:29:34 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*new;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		cont = f(lst->content);
		elem = ft_lstnew(cont);
		if (!elem)
		{
			free(cont);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, elem);
		lst = lst->next;
	}
	return (new);
}
