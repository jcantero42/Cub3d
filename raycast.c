#include <math.h>
#include <limits.h>
#include "cubed.h"

void set_direction(t_game *g)
{
	if (g->ra < 0)
		g->ra += 2 * M_PI;
	if (g->ra > 2 * M_PI)
		g->ra -= 2 * M_PI;
	g->up = (g->ra > 0 && g->ra < M_PI);
	g->down = !g->up;
	g->right = (g->ra < M_PI_2 || g->ra > 3 * M_PI_2);
	g->left = !g->right;
}

void	set_delta(t_game *g)
{
	if (g->right)
		g->dx = 0.5 + (round(g->px) - g->px);
	else
		g->dx = 0.5 - (round(g->px) - g->px);

	if (g->up)
		g->dy = 0.5 - (round(g->py) - g->py);
	else
		g->dy = 0.5 + (round(g->py) - g->py);
}

void	set_steps(t_game *g)
{
	g->step_x = fabs(1 / tan(g->ra));
	g->step_y = fabs(tan(g->ra));
}

void	first_intersections(t_game *g)
{
	if (g->up)
		g->hy = g->py - g->dy;
	else
		g->hy = g->py + g->dy;
	if (g->right)
		g->hx = g->px + g->dy / fabs(tan(g->ra));
	else
		g->hx = g->px - g->dy / fabs(tan(g->ra));
	if (g->right)
		g->vx = g->px + g->dx;
	else
		g->vx = g->px - g->dx;
	if (g->up)
		g->vy = g->py - g->dx * fabs(tan(g->ra));
	else
		g->vy = g->py + g->dx * fabs(tan(g->ra));
}

void	horizontal_intersection(t_game *g)
{
	while (1)
	{
		char c = check_horizontal(g);
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
		if (g->up)
			g->hy -= 1;
		else
			g->hy += 1;
	}
}

void	vertical_intersection(t_game *g)
{
	while (1)
	{
		char c = check_vertical(g);
		if (c == 'E')
		{
			g->vy = INT_MAX;
			g->vx = INT_MAX;
			break ;
		}
		else if (c == '1')
			break ;
		if (g->up)
			g->vy -= g->step_y;
		else
			g->vy += g->step_y;
		if (g->right)
			g->vx += 1;
		else
			g->vx -= 1;
	}
}

void	compute_distance(t_game *g)
{
	g->dh = hypot(g->hx - g->px, g->hy - g->py);
	g->dv = hypot(g->vx - g->px, g->vy - g->py);

	g->dh *= cos(fabs(g->ra - g->pa));
	g->dv *= cos(fabs(g->ra - g->pa));

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
	g->h = (0.5 * WIN_WIDTH) / (2 * g->dmin * fabs(tan(FOV / 2)));
}

void	cast_rays(t_game *g)
{
	int i = 0;
	g->ra = g->pa + (FOV / 2);
	g->sa = FOV / WIN_WIDTH;
	set_delta(g);
	while (i < WIN_WIDTH)
	{
		set_direction(g);
		set_steps(g);
		first_intersections(g);
		horizontal_intersection(g);
		vertical_intersection(g);
		compute_distance(g);
		paint_column(g, i, g->h);
		g->ra -= g->sa;
		i++;
	}
}
