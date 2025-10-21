#include "mlx_linux/mlx.h"
#include "cubed.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define FOV 1.05

#define PI 3.14159265359

char	**init_map()
{
	char	**map;

	map = (char **)malloc(5 * sizeof(char *));
	for (int i = 0; i < 5; i++)
	{
		map[i] = (char *)malloc(6 * sizeof(char));
	}
	ft_strlcpy(map[0], "11111", 6);
	ft_strlcpy(map[1], "10001", 6);
	ft_strlcpy(map[2], "10101", 6);
	ft_strlcpy(map[3], "10001", 6);
	ft_strlcpy(map[4], "11111", 6);
	return (map);
}

t_game	*init_game()
{
	t_game	*g;
	
	g = (t_game *)malloc(sizeof(t_game));
	g->player_x = 2;
	g->player_y = 3;
	g->map = init_map();
	g->width = 5;
	g->height = 5;
	g->angle = PI / 2;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT,  "cubed");
	return (g);
}

char	check_vertical(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->right)
		tile_x = ceil(g->ver_x);
	else
		tile_x = floor(g->ver_x);
	tile_y = round(g->ver_y);
	// printf("map[%lf][%lf]\n", g->ver_y, g->ver_x);
	// printf("map[%d][%d]\n", tile_y, tile_x);
	// TODO: check for out of bounds
	return (g->map[tile_y][tile_x]);
}

char	check_horizontal(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->up)
		tile_y = floor(g->hor_y);
	else
		tile_y = ceil(g->hor_y);
	tile_x = round(g->hor_x);
	// printf("map[%lf][%lf]\n", g->hor_y, g->hor_x);
	// printf("map[%d][%d]\n", tile_y, tile_x);
	// TODO: check for out of bounds
	return (g->map[tile_y][tile_x]);
}

int main(void)
{
	t_game	*g;

	g = init_game();

	int i = 0;
	double ray_ang = g->angle - (FOV / 2);
	// printf("ray_ang %lf\n", ray_ang * 360 / (2 * PI));
	// for (int i = 0; i < 5; i++)
	// 	printf("%s\n", g->map[i]);
	// printf("player: %lf %lf\n", g->player_x, g->player_y);
	double step_ang = FOV / WIN_WIDTH;
	while (i < WIN_WIDTH)
	{
		g->up = ray_ang < PI && ray_ang > 0;
		g->down = !g->up;
		g->left = ray_ang > (PI / 2) && ray_ang < (3 * PI / 2);
		g->right = !g->left;
		// g->up ? printf("up\n") : printf("down\n");
		// g->right ? printf("right\n") : printf("left\n");

		if (g->right)
			g->delta_x = 0.5 + (round(g->player_x) - g->player_x);
		else
			g->delta_x = 0.5 - (round(g->player_x) - g->player_x);
		// printf("dx %lf\n", g->delta_x);

		if (g->up)
			g->delta_y = 0.5 - (round(g->player_y) - g->player_y);
		else
			g->delta_y = 0.5 + (round(g->player_y) - g->player_y);
		// printf("dy %lf\n", g->delta_y);

		// first intersections

		if (g->up)
			g->hor_y = g->player_y - g->delta_y;
		else
			g->hor_y = g->player_y + g->delta_y;
		if (g->right)
			g->hor_x = g->player_x + g->delta_y / tan(ray_ang);
		else
			g->hor_x = g->player_x - g->delta_y / tan(ray_ang);
		// printf("hx %lf\n", g->hor_x);
		// printf("hy %lf\n", g->hor_y);

		if (g->right)
			g->ver_x = g->player_x + g->delta_x;
		else
			g->ver_x = g->player_x - g->delta_x;
		if (g->up)
			g->ver_y = g->player_y - g->delta_x * tan(ray_ang);
		else
			g->ver_y = g->player_y + g->delta_x * tan(ray_ang);
		// printf("vx %lf\n", g->ver_x);
		// printf("vy %lf\n", g->ver_y);

		// steps
		
		g->step_x = fabs(1 / tan(ray_ang));
		g->step_y = fabs(tan(ray_ang));
		// printf("sx %lf\n", g->step_x);
		// printf("sy %lf\n", g->step_y);
		
		while (1)
		{
			// printf("horizontal...\n");
			char c = check_horizontal(g);
			if (c == 'E')
			{
				// printf("HOR ERROR\n");
				g->hor_y = 0;
				g->hor_x = 0;
				break ;
			}
			else if (c == '1')
				break ;
			if (g->right)
				g->hor_x += g->step_x;
			else
				g->hor_x -= g->step_x;
			if (g->up)
				g->hor_y -= 1;
			else
				g->hor_y += 1;
		}
		while (1)
		{
			// printf("vertical...\n");
			char c = check_vertical(g);
			if (c == 'E')
			{
				// printf("HOR ERROR\n");
				g->ver_y = 0;
				g->ver_x = 0;
				break ;
			}
			else if (c == '1')
				break ;
			if (g->up)
				g->ver_y -= g->step_y;
			else
				g->ver_y += g->step_y;
			if (g->right)
				g->ver_x += 1;
			else
				g->ver_x -= 1;
		}

		printf("hx %lf hy %lf\n", g->hor_x, g->hor_y);
		printf("vx %lf vy %lf\n", g->ver_x, g->ver_y);

		// next
		ray_ang += step_ang;
		i++;
		if (i == 3)
			break ;
	}

	// mlx_loop(g->mlx);
}
