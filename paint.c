/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:12:04 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:12:06 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	pixel_get(t_img	*img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	paint_floor_ceil(t_game *g, int x)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		pixel_put(g, x, i, g->ceiling_color);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		pixel_put(g, x, i, g->floor_color);
		i++;
	}
}

void	paint_column(t_game *g, int x, int h)
{
	int	i;

	paint_floor_ceil(g, x);
	i = ft_max(WIN_HEIGHT / 2 - h / 2, 0);
	while (i < ft_min(WIN_HEIGHT / 2 + h / 2, WIN_HEIGHT))
	{
		if (g->dir == NORTH)
			no_pixel_put(g, i, x);
		else if (g->dir == SOUTH)
			so_pixel_put(g, i, x);
		else if (g->dir == EAST)
			ea_pixel_put(g, i, x);
		else if (g->dir == WEST)
			we_pixel_put(g, i, x);
		i++;
	}
}
