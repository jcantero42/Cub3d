/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:11:14 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:11:15 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	within_boundaries(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return (0);
	return (1);
}

int	walled_map(t_game *g, int x, int y)
{
	if (!within_boundaries(g, x, y))
		return (0);
	if (g->map[y][x] == ' ')
		return (0);
	if (g->map[y][x] == '0')
	{
		g->map[y][x] = '.';
		if (!walled_map(g, x - 1, y))
			return (0);
		if (!walled_map(g, x + 1, y))
			return (0);
		if (!walled_map(g, x, y + 1))
			return (0);
		if (!walled_map(g, x, y - 1))
			return (0);
	}
	return (1);
}

void	restore_map(t_game *g, int x, int y)
{
	if (g->map[y][x] == '.')
	{
		g->map[y][x] = '0';
		restore_map(g, x, y - 1);
		restore_map(g, x, y + 1);
		restore_map(g, x - 1, y);
		restore_map(g, x + 1, y);
	}
}
