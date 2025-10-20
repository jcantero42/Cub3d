#include "mlx_linux/mlx.h"
#include "cubed.h"
#include "libft/libft.h"
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

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
	g->dir_x = 0;
	g->dir_y = -1;
	g->plane_x = 0.66;
	g->plane_y = 0;
	g->time = 0;
	g->old_time = 0;
	g->map = init_map();
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,  "cubed");
	return (g);
}

int main(void)
{
	t_game	*g;

	g = init_game();
	mlx_loop(g->mlx);
}
