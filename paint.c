#include "cubed.h"
#include "libft/libft.h"

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
	while (i < WIN_HEIGHT / 2)
	{
		pixel_put(g, x, i, 0x0087ceeb);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		pixel_put(g, x, i, 0x0000008b);
		i++;
	}
	i = ft_max(WIN_HEIGHT / 2 - h / 2, 0);
	while (i < ft_min(WIN_HEIGHT / 2 + h / 2, WIN_HEIGHT))
	{
		pixel_put(g, x, i, 0x00006400);
		i++;
	}
}
