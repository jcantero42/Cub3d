/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:12:44 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:12:45 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "libft/libft.h"

void	time_diff(t_game *g)
{
	gettimeofday(&g->now, NULL);
	g->ms = (g->now.tv_sec - g->then.tv_sec) * 1000;
	g->ms += (g->now.tv_usec - g->then.tv_usec) / 1000;
	ft_memcpy(&g->then, &g->now, sizeof(g->now));
}
