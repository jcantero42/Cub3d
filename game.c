#include "cubed.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <math.h>

char	**init_map()
{
	char	**map;

	map = (char **)malloc(13 * sizeof(char *));
	for (int i = 0; i < 13; i++)
	{
		map[i] = (char *)malloc(13 * sizeof(char));
	}
	ft_strlcpy(map[0], "1111111111", 11);
	ft_strlcpy(map[1], "1000000001", 11);
	ft_strlcpy(map[2], "1001000001", 11);
	ft_strlcpy(map[3], "1000000001", 11);
	ft_strlcpy(map[4], "1000000111", 11);
	ft_strlcpy(map[5], "1000000001", 11);
	ft_strlcpy(map[6], "1010000111", 11);
	ft_strlcpy(map[7], "1000000001", 11);
	ft_strlcpy(map[8], "1000000001", 11);
	ft_strlcpy(map[9], "1111111111", 11);
	return (map);
}

void	init_game(t_game *g)
{
	
	// g = (t_game *)malloc(sizeof(t_game));
	// g->px = 3;
	// g->py = 3;
	// g->map = init_map();
	// g->width = 10;
	// g->height = 10;
	g->pa = 3 * M_PI_2;
	if (g->start_direction == NORTH)
	{
		g->pa = 3 * M_PI_2;
	}
	else if (g->start_direction == SOUTH)
	{
		g->pa = M_PI_2;
	}
	else if (g->start_direction == EAST)
	{
		g->pa = 0;
	}
	else if (g->start_direction == WEST)
	{
		g->pa = M_PI;
	}
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT,  "cubed");
	g->no_img = mlx_xpm_file_to_image(g->mlx, "./textures/north.xpm", &g->no_w, &g->no_h);
	g->so_img = mlx_xpm_file_to_image(g->mlx, "./textures/south.xpm", &g->so_w, &g->so_h);
	g->ea_img = mlx_xpm_file_to_image(g->mlx, "./textures/east.xpm", &g->ea_w, &g->ea_h);
	g->we_img = mlx_xpm_file_to_image(g->mlx, "./textures/west.xpm", &g->we_w, &g->we_h);
}
