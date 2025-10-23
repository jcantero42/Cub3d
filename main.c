#include "mlx_linux/mlx.h"
#include "cubed.h"
#include <limits.h>
#include <stdlib.h>

int	game_loop(t_game *g)
{
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
	cast_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_destroy_image(g->mlx, g->img);
	return (0);
}

int	terminate(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
}

int main(void)
{
	t_game	*g;

	g = init_game();
	mlx_hook(g->win, KEYPRESS, 1L<<0, update_game, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	mlx_hook(g->win, ON_DESTROY, 0L, terminate, g);
	mlx_loop(g->mlx);
}
