/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:13:51 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 13:14:05 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "cubed.h"
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include "libft/libft.h"

int	game_loop(t_game *g)
{
	time_diff(g);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
	cast_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	mlx_destroy_image(g->mlx, g->img);
	return (0);
}

int	terminate(t_game *g)
{
	mlx_destroy_image(g->mlx, g->no_img);
	mlx_destroy_image(g->mlx, g->so_img);
	mlx_destroy_image(g->mlx, g->ea_img);
	mlx_destroy_image(g->mlx, g->we_img);
	mlx_destroy_window(g->mlx, g->win);
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

int	validate_args(int ac, char **av)
{
	char	*format;

	if (ac != 2)
		return (0);
	format = ft_strrchr(av[1], '.');
	if (!format || ft_strncmp(format, ".cub", 4) != 0 || format[4] != '\0')
		return (0);
	return (1);
}

t_game	*init_struct(void)
{
	t_game	*g;

	g = (t_game *)ft_calloc(1, sizeof(t_game));
	g->ceiling_color = -1;
	g->floor_color = -1;
	return (g);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (!validate_args(ac, av))
		return (printf("Invalid arguments. Try again\n"), 1);
	g = init_struct();
	if (!parse_file(av[1], g))
		return (free_parser(g), printf("Error with parsing\n"), 1);
	init_game(g);
	mlx_hook(g->win, KEYPRESS, 1L << 0, update_game, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	mlx_hook(g->win, ON_DESTROY, 0L, terminate, g);
	mlx_loop(g->mlx);
}
