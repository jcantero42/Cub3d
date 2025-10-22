#include "mlx_linux/mlx.h"
#include "cubed.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	t_game	*g;

	g = init_game();

	int i = 0;
	g->ra = g->pa + (FOV / 2);
	double step_ang = FOV / WIN_WIDTH;
	while (i < WIN_WIDTH)
	{
		g->up = g->ra < PI && g->ra > 0;
		g->down = !g->up;
		g->left = g->ra > (PI / 2) && g->ra < (3 * PI / 2);
		g->right = !g->left;

		if (g->right)
			g->dx = 0.5 + (round(g->px) - g->px);
		else
			g->dx = 0.5 - (round(g->px) - g->px);

		if (g->up)
			g->dy = 0.5 - (round(g->py) - g->py);
		else
			g->dy = 0.5 + (round(g->py) - g->py);

		// first intersections

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

		// steps
		
		g->step_x = fabs(1 / tan(g->ra));
		g->step_y = fabs(tan(g->ra));
		
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


		g->dh = sqrt((g->hx - g->px) * (g->hx - g->px) + (g->hy - g->py) * (g->hy - g->py));
		g->dv = sqrt((g->vx - g->px) * (g->vx - g->px) + (g->vy - g->py) * (g->vy - g->py));
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
		
		g->dmin = g->dmin * fabs(sin(g->ra));

		g->h = (0.5 * WIN_WIDTH) / (2 * g->dmin * fabs(tan(FOV / 2)));

		paint_column(g, i, g->h);
		g->ra -= step_ang;
		i++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_loop(g->mlx);
}
