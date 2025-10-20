#include "mlx_linux/mlx.h"
#include "cubed.h"
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(void)
{
	t_game	*g;
	
	g = (t_game *)malloc(sizeof(t_game));
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,  "cubed");
	mlx_loop(g->mlx);
}
