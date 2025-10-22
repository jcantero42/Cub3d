#include "mlx_linux/mlx.h"
#include "cubed.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

char	**init_map()
{
	char	**map;

	map = (char **)malloc(5 * sizeof(char *));
	for (int i = 0; i < 5; i++)
	{
		map[i] = (char *)malloc(6 * sizeof(char));
	}
	ft_strlcpy(map[0], "11111", 6);
	ft_strlcpy(map[1], "10101", 6);
	ft_strlcpy(map[2], "10001", 6);
	ft_strlcpy(map[3], "10001", 6);
	ft_strlcpy(map[4], "11111", 6);
	return (map);
}

t_game	*init_game()
{
	t_game	*g;
	
	g = (t_game *)malloc(sizeof(t_game));
	g->px = 2;
	g->py = 3;
	g->map = init_map();
	g->width = 5;
	g->height = 5;
	g->angle = PI / 2;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT,  "cubed");
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
	return (g);
}

char	check_vertical(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->right)
		tile_x = ceil(g->vx);
	else
		tile_x = floor(g->vx);
	tile_y = round(g->vy);
	if (tile_x > g->width - 1 || tile_x < 0)
		return ('E');
	if (tile_y > g->height - 1 || tile_y < 0)
		return ('E');
	return (g->map[tile_y][tile_x]);
}

char	check_horizontal(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->up)
		tile_y = floor(g->hy);
	else
		tile_y = ceil(g->hy);
	tile_x = round(g->hx);
	if (tile_x > g->width - 1 || tile_x < 0)
		return ('E');
	if (tile_y > g->height - 1 || tile_y < 0)
		return ('E');
	return (g->map[tile_y][tile_x]);
}

int main(void)
{
	t_game	*g;

	g = init_game();

	int i = 0;
	double ray_ang = g->angle + (FOV / 2);
	double step_ang = FOV / WIN_WIDTH;
	while (i < WIN_WIDTH)
	{
		g->up = ray_ang < PI && ray_ang > 0;
		g->down = !g->up;
		g->left = ray_ang > (PI / 2) && ray_ang < (3 * PI / 2);
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
			g->hx = g->px + g->dy / fabs(tan(ray_ang));
		else
			g->hx = g->px - g->dy / fabs(tan(ray_ang));

		if (g->right)
			g->vx = g->px + g->dx;
		else
			g->vx = g->px - g->dx;
		if (g->up)
			g->vy = g->py - g->dx * fabs(tan(ray_ang));
		else
			g->vy = g->py + g->dx * fabs(tan(ray_ang));

		// steps
		
		g->step_x = fabs(1 / tan(ray_ang));
		g->step_y = fabs(tan(ray_ang));
		
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
		

		g->h = (0.5 * WIN_WIDTH) / (2 * g->dmin * tan(FOV / 2));

		printf("hey\n");
		printf("i %d\nh %lf\n", i, g->h);
		paint_column(g, i, g->h);
		printf("bye\n");
		ray_ang -= step_ang;
		i++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_loop(g->mlx);
}
