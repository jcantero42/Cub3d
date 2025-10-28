#include "cubed.h"
#include "libft/libft.h"
#include "mlx_int.h"
#include <math.h>

void	pixel_put(t_game *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

// not really sure about this function
int	pixel_get(t_img	*img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
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
		if (g->dir == NORTH)
		{
			double ry;
			double rx;

			ry = (i - (WIN_HEIGHT / 2.0 - h / 2.0)) / (double)h;
			rx = 0.5 + (round(g->hx) - g->hx);
			// printf("%.3lf, %.3lf\n", rx, ry);
			// pixel_put(g, x, i, 0x00FF0000);
			pixel_put(g, x, i, pixel_get(g->no_img, round(g->no_img->width * rx + 0), round(g->no_img->height * ry + 0)));
		}
		else if (g->dir == SOUTH)
			pixel_put(g, x, i, 0x000000FF);
		else if (g->dir == WEST)
			pixel_put(g, x, i, 0X00FFA500);
		else if (g->dir == EAST)
			pixel_put(g, x, i, 0x0000FF00);
		i++;
	}
}
