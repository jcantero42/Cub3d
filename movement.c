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

int	check_move(t_game *g, double x, double y)
{
	if (g->map[(int)round(y)][(int)round(x)] == '1')
		return (0);
	if (g->map[(int)round(y + PLAYER_BARRIER)][(int)round(x + PLAYER_BARRIER)] == '1')
		return (0);
	if (g->map[(int)round(y - PLAYER_BARRIER)][(int)round(x - PLAYER_BARRIER)] == '1')
		return (0);
	if (g->map[(int)round(y + PLAYER_BARRIER)][(int)round(x - PLAYER_BARRIER)] == '1')
		return (0);
	if (g->map[(int)round(y - PLAYER_BARRIER)][(int)round(x + PLAYER_BARRIER)] == '1')
		return (0);
	return (1);
}

void	try_move(t_game *g, double x, double y)
{
	if (check_move(g, x, y))
	{
		g->px = x;
		g->py = y;
	}
	else if (check_move(g, x, g->py))
		g->px = x;
	else if (check_move(g, g->px, y))
		g->py = y;
}

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
	try_move(g, g->npx, g->npy);
}
