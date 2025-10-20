/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:57:38 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/08 20:11:38 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		pl = *lst;
		while (pl->next != NULL)
			pl = pl->next;
		pl->next = new;
	}
	return ;
}
