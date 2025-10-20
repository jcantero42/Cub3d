#include "mlx_linux/mlx.h"
#include "cubed.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>

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
	g->player_x = 3;
	g->player_y = 3;
	g->map = init_map();
	g->angle = PI / 2;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT,  "cubed");
	return (g);
}

int main(void)
{
	t_game	*g;

	g = init_game();

	int i = 0;
	double ray_ang = g->angle - (FOV / 2);
	double step_ang = FOV / WIN_WIDTH;
	while (i < WIN_WIDTH)
	{
		g->up = ray_ang < PI && ray_ang > 0;
		g->down = !g->up;
		g->left = ray_ang > (PI / 2) && ray_ang < (3 * PI / 2);
		g->right = !g->left;

		if (g->right)
			g->delta_x = round(g->player_x) - g->player_x + 0.5;
		else
			g->delta_x = round(g->player_x) + g->player_x + 0.5;

		if (g->up)
			g->delta_y = round(g->player_y) + g->player_y + 0.5;
		else
			g->delta_y = round(g->player_y) - g->player_y + 0.5;

		// TODO: working here

		ray_ang += step_ang;
		i++;
	}

	mlx_loop(g->mlx);
}
