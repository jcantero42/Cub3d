/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:37 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/09 16:20:49 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pn;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		pn = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pn;
	}
	return ;
}
