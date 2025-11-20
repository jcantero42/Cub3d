/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:11:24 by marcolop          #+#    #+#             */
/*   Updated: 2025/11/20 11:11:25 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "mlx_linux/mlx.h"
#include <math.h>
#include <sys/time.h>

void	exit_bad_textures(t_game *g)
{
	if (g->no_img)
		mlx_destroy_image(g->mlx, g->no_img);
	if (g->so_img)
		mlx_destroy_image(g->mlx, g->so_img);
	if (g->we_img)
		mlx_destroy_image(g->mlx, g->we_img);
	if (g->ea_img)
		mlx_destroy_image(g->mlx, g->ea_img);
	mlx_destroy_display(g->mlx);
	free_map(g->map);
	free(g->no_texture);
	free(g->so_texture);
	free(g->ea_texture);
	free(g->we_texture);
	free(g->mlx);
	free(g);
	exit(0);
}

void	init_game(t_game *g)
{
	g->pa = 3 * M_PI_2;
	if (g->start_direction == NORTH)
		g->pa = 3 * M_PI_2;
	else if (g->start_direction == SOUTH)
		g->pa = M_PI_2;
	else if (g->start_direction == WEST)
		g->pa = 0;
	else if (g->start_direction == EAST)
		g->pa = M_PI;
	gettimeofday(&g->then, NULL);
	g->mlx = mlx_init();
	g->no_img = mlx_xpm_file_to_image(g->mlx, g->no_texture,
			&g->no_w, &g->no_h);
	g->so_img = mlx_xpm_file_to_image(g->mlx, g->so_texture,
			&g->so_w, &g->so_h);
	g->ea_img = mlx_xpm_file_to_image(g->mlx, g->ea_texture,
			&g->ea_w, &g->ea_h);
	g->we_img = mlx_xpm_file_to_image(g->mlx, g->we_texture,
			&g->we_w, &g->we_h);
	if (!g->no_img || !g->so_img || !g->ea_img || !g->we_img)
	{
		printf("Error\nCould not load textures\n");
		exit(0);
	}
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "cubed");
}
