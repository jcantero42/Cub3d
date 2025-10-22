#include "mlx_linux/mlx.h"
#include "cubed.h"
#include <limits.h>

int main(void)
{
	t_game	*g;

	g = init_game();

	while (1)
	{
		g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
		g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
		cast_rays(g);
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
		mlx_destroy_image(g->mlx, g->img);
	mlx_loop(g->mlx);
	}
}
