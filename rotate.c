#include "cubed.h"
#include <stdio.h>

void	rotate_perspective(t_game *g, int keycode)
{
	if (keycode == KEY_LEFT)
		g->pa += ROTATE_STEP;
	else if (keycode == KEY_RIGHT)
		g->pa -= ROTATE_STEP;
	if (g->pa > 2 * PI)
		g->pa -= 2 * PI;
	else if (g->pa < 0)
		g->pa += 2 * PI;
}
