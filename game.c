#include "cubed.h"
#include "mlx_linux/mlx.h"
#include <math.h>
#include <sys/time.h>

void	init_game(t_game *g)
{
	g->pa = 3 * M_PI_2;
	if (g->start_direction == NORTH)
		g->pa = 3 * M_PI_2;
	else if (g->start_direction == SOUTH)
		g->pa = M_PI_2;
	else if (g->start_direction == WEST)
		g->pa = 0;
	else if (g->start_direction == EAST)
		g->pa = M_PI;
	gettimeofday(&g->then, NULL);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "cubed");
	g->no_img = mlx_xpm_file_to_image(g->mlx, g->no_texture,
			&g->no_w, &g->no_h);
	g->so_img = mlx_xpm_file_to_image(g->mlx, g->so_texture,
			&g->so_w, &g->so_h);
	g->ea_img = mlx_xpm_file_to_image(g->mlx, g->ea_texture,
			&g->ea_w, &g->ea_h);
	g->we_img = mlx_xpm_file_to_image(g->mlx, g->we_texture,
			&g->we_w, &g->we_h);
}
