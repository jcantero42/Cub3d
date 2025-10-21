#include "cubed.h"

void	pixel_put(t_game *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

void	paint_column(t_game *g, int x, int h)
{
	int	i;

	(void)h;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		pixel_put(g, x, i, 0x000000FF);
		i++;
	}
	i = WIN_HEIGHT / 2 - h / 2;
	while (i < WIN_HEIGHT / 2 + h / 2)
	{
		pixel_put(g, x, i, 0x0000FF00);
		i++;
	}
}
