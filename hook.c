#include "cubed.h"

int	update_game(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move_player(g, keycode);
	else if (keycode == KEY_A)
		move_player(g, keycode);
	else if (keycode == KEY_S)
		move_player(g, keycode);
	else if (keycode == KEY_D)
		move_player(g, keycode);
	else if (keycode == KEY_RIGHT)
		g->pa -= PLAYER_STEP;
	else if (keycode == KEY_LEFT)
		g->pa += PLAYER_STEP;
	else if (keycode == KEY_ESC)
		terminate(g);
	return (0);
}
