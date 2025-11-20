/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:12:13 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:12:20 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <limits.h>
#include "cubed.h"

void	compute_distance(t_game *g)
{
	double	diff;

	g->dh = hypot(g->hx - g->px, g->hy - g->py);
	g->dv = hypot(g->vx - g->px, g->vy - g->py);
	diff = g->ra - g->pa;
	if (diff < -M_PI)
		diff += 2 * M_PI;
	if (diff > M_PI)
		diff -= 2 * M_PI;
	g->dh *= cos(diff);
	g->dv *= cos(diff);
	if (g->dh < g->dv)
	{
		g->fx = g->hx;
		g->fy = g->hy;
		g->dmin = g->dh;
	}
	else
	{
		g->fx = g->vx;
		g->fy = g->vy;
		g->dmin = g->dv;
	}
	g->h = (WIN_WIDTH) / (2 * g->dmin * fabs(tan(FOV / 2)));
}

void	cast_rays(t_game *g)
{
	int	i;

	g->ra = g->pa + (FOV / 2);
	g->sa = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		set_direction(g);
		set_delta(g);
		set_steps(g);
		first_intersections(g);
		horizontal_intersection(g);
		vertical_intersection(g);
		compute_distance(g);
		set_cardinal(g);
		paint_column(g, i, g->h);
		g->ra -= g->sa;
		i++;
	}
}
