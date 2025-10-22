#include "cubed.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <stdlib.h>

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
	g->pa = PI / 2;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT,  "cubed");
	return (g);
}
