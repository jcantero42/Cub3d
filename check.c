#include <math.h>
#include "cubed.h"

char	check_horizontal(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->up)
		tile_y = floor(g->hy);
	else
		tile_y = ceil(g->hy);
	tile_x = round(g->hx);
	
    // int tile_x = (int)floor(g->hx);
    // int tile_y = (int)round(g->hy);
	if (tile_x > g->width - 1 || tile_x < 0)
		return ('E');
	if (tile_y > g->height - 1 || tile_y < 0)
		return ('E');
	return (g->map[tile_y][tile_x]);
}

char	check_vertical(t_game *g)
{
	int	tile_x;
	int	tile_y;

	if (g->right)
		tile_x = ceil(g->vx);
	else
		tile_x = floor(g->vx);
	tile_y = round(g->vy);
	
    // int tile_x = (int)round(g->vx);
    // int tile_y = (int)floor(g->vy);
	if (tile_x > g->width - 1 || tile_x < 0)
		return ('E');
	if (tile_y > g->height - 1 || tile_y < 0)
		return ('E');
	return (g->map[tile_y][tile_x]);
}
