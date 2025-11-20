/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:12:36 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:12:37 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <math.h>

void	no_pixel_put(t_game *g, int i, int x)
{
	double	y_ratio;
	double	x_ratio;

	y_ratio = (i - (WIN_HEIGHT / 2.0 - g->h / 2.0)) / (double)g->h;
	x_ratio = 0.5 - (round(g->hx) - g->hx);
	pixel_put(g, x, i, pixel_get(g->no_img, round(g->no_img->width * x_ratio),
			round(g->no_img->height * y_ratio)));
}

void	so_pixel_put(t_game *g, int i, int x)
{
	double	y_ratio;
	double	x_ratio;

	y_ratio = (i - (WIN_HEIGHT / 2.0 - g->h / 2.0)) / (double)g->h;
	x_ratio = 0.5 + (round(g->hx) - g->hx);
	pixel_put(g, x, i, pixel_get(g->so_img, round(g->so_img->width * x_ratio),
			round(g->so_img->height * y_ratio)));
}

void	ea_pixel_put(t_game *g, int i, int x)
{
	double	y_ratio;
	double	x_ratio;

	y_ratio = (i - (WIN_HEIGHT / 2.0 - g->h / 2.0)) / (double)g->h;
	x_ratio = 0.5 + (round(g->vy) - g->vy);
	pixel_put(g, x, i, pixel_get(g->ea_img, round(g->ea_img->width * x_ratio),
			round(g->ea_img->height * y_ratio)));
}

void	we_pixel_put(t_game *g, int i, int x)
{
	double	y_ratio;
	double	x_ratio;

	y_ratio = (i - (WIN_HEIGHT / 2.0 - g->h / 2.0)) / (double)g->h;
	x_ratio = 0.5 - (round(g->vy) - g->vy);
	pixel_put(g, x, i, pixel_get(g->we_img, round(g->we_img->width * x_ratio),
			round(g->we_img->height * y_ratio)));
}
