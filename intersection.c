/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:11:42 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:11:45 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <math.h>
#include <limits.h>

void	first_intersections(t_game *g)
{
	if (g->right)
		g->hx = g->px + g->dy / fabs(tan(g->ra));
	else
		g->hx = g->px - g->dy / fabs(tan(g->ra));
	if (g->down)
		g->hy = g->py + g->dy;
	else
		g->hy = g->py - g->dy;
	if (g->right)
		g->vx = g->px + g->dx;
	else
		g->vx = g->px - g->dx;
	if (g->down)
		g->vy = g->py + g->dx * fabs(tan(g->ra));
	else
		g->vy = g->py - g->dx * fabs(tan(g->ra));
}

void	horizontal_intersection(t_game *g)
{
	char	c;

	while (1)
	{
		c = check_horizontal(g);
		if (c == 'E')
		{
			g->hy = INT_MAX;
			g->hx = INT_MAX;
			break ;
		}
		else if (c == '1')
			break ;
		if (g->right)
			g->hx += g->step_x;
		else
			g->hx -= g->step_x;
		if (g->down)
			g->hy += 1;
		else
			g->hy -= 1;
	}
}

void	vertical_intersection(t_game *g)
{
	char	c;

	while (1)
	{
		c = check_vertical(g);
		if (c == 'E')
		{
			g->vy = INT_MAX;
			g->vx = INT_MAX;
			break ;
		}
		else if (c == '1')
			break ;
		if (g->right)
			g->vx += 1;
		else
			g->vx -= 1;
		if (g->down)
			g->vy += g->step_y;
		else
			g->vy -= g->step_y;
	}
}
