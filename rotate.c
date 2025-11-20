#include "cubed.h"
#include <stdio.h>
#include <math.h>

void	rotate_perspective(t_game *g, int keycode)
{
	if (keycode == KEY_LEFT)
		g->pa += ROTATE_STEP;
	else if (keycode == KEY_RIGHT)
		g->pa -= ROTATE_STEP;
	if (g->pa > 2 * M_PI)
		g->pa -= 2 * M_PI;
	else if (g->pa < 0)
		g->pa += 2 * M_PI;
}
