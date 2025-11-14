#include "cubed.h"
#include <math.h>

void	set_direction(t_game *g)
{
	if (g->ra < 0)
		g->ra += 2 * M_PI;
	if (g->ra > 2 * M_PI)
		g->ra -= 2 * M_PI;
	g->down = (g->ra >= 0 && g->ra <= M_PI);
	g->up = !g->down;
	g->left = (g->ra <= M_PI_2 || g->ra >= 3 * M_PI_2);
	g->right = !g->left;
}

void	set_delta(t_game *g)
{
	if (g->right)
		g->dx = 0.5 + (round(g->px) - g->px);
	else
		g->dx = 0.5 - (round(g->px) - g->px);
	if (g->down)
		g->dy = 0.5 + (round(g->py) - g->py);
	else
		g->dy = 0.5 - (round(g->py) - g->py);
}

void	set_steps(t_game *g)
{
	if (fabs(cos(g->ra)) < 1e-6)
	{
		g->step_x = 0;
		g->step_y = 1e6;
	}
	else
	{
		g->step_x = fabs(1 / tan(g->ra));
		g->step_y = fabs(tan(g->ra));
	}
}

void	set_cardinal(t_game *g)
{
	if (g->up && g->dmin == g->dh)
		g->dir = NORTH;
	else if (g->down && g->dmin == g->dh)
		g->dir = SOUTH;
	else if (g->right && g->dmin == g->dv)
		g->dir = WEST;
	else if (g->left && g->dmin == g->dv)
		g->dir = EAST;
}
