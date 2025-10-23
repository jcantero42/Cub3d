#include "cubed.h"
#include <math.h>
#include <stdio.h>

void	set_move_angle(t_game *g, int keycode)
{
	if (keycode == KEY_W)
		g->ma = g->pa;
	else if (keycode == KEY_A)
		g->ma = g->pa + PI / 2;
	else if (keycode == KEY_S)
		g->ma = g->pa + PI;
	else if (keycode == KEY_D)
		g->ma = g->pa + 3 * PI / 2;
	if (g->ma > 2 * PI)
		g->ma -= 2 * PI;
	else if (g->ma < 0)
		g->ma += 2 * PI;
}

// TODO: solve problem when next to wall
void	move_player(t_game *g, int keycode)
{
	int	up;
	int	left;

	set_move_angle(g, keycode);
	g->nx = PLAYER_STEP * fabs(cos(g->ma));
	g->ny = PLAYER_STEP * fabs(sin(g->ma));
	up = g->ma < PI && g->ma > 0;
	left = g->ma > (PI / 2) && g->ma < (3 * PI / 2);
	if (up)
		g->npy = g->py - g->ny;
	else
		g->npy = g->py + g->ny;
	if (left)
		g->npx = g->px - g->nx;
	else
		g->npx = g->px + g->nx;
	if (g->map[(int)round(g->npy)][(int)round(g->npx)] == '1')
		return ;
	g->px = g->npx;
	g->py = g->npy;
}
