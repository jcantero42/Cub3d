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

	cast_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_loop(g->mlx);
}
