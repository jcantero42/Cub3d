#include "cubed.h"
#include <stdio.h>

int	update_game(int keycode, t_game *g)
{
	(void)g;
	if (keycode == KEY_W)
		g->py -= PLAYER_STEP;
	else if (keycode == KEY_A)
		g->px -= PLAYER_STEP;
	else if (keycode == KEY_S)
		g->py += PLAYER_STEP;
	else if (keycode == KEY_D)
		g->px += PLAYER_STEP;
	else if (keycode == KEY_RIGHT)
		g->pa -= PLAYER_STEP;
	else if (keycode == KEY_LEFT)
		g->pa += PLAYER_STEP;
	else if (keycode == KEY_ESC)
		printf("ESC\n");
	else
		printf("%d\n", keycode);
	return (0);
}
