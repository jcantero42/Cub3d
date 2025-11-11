/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:07:53 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 14:07:55 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	parse_file(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!parse_config(fd, game))
		return (0);
	if (!parse_map(fd, game))
		return (0);
	return (1);
}

int	parse_config(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!parse_config_line(line, game))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!config_is_complete(game))
	{
		close(fd);
		return (0);
	}
	return (1);
}

int	parse_config_line(char *line, t_game *game)
{
	char	**split;
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(line, " \n\t");
	if (!trimmed)
		return (0);
	split = ft_split(trimmed, ' ');
	free(trimmed);
	if (!split || count_split(split) != 2)
		return (free_split(split), 0);
	result = 1;
	if (ft_strcmp(split[0], "NO") == 0)
		game->no_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		game->so_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		game->ea_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		game->we_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "F") == 0 || ft_strcmp(split[0], "C") == 0)
		result = parse_color_line(split[1], game, split[0][0]);
	else
		result = 0;
	return (free_split(split), result);
}

int	parse_color_line(char *value, t_game *game, char type)
{
	int	color;

	color = parse_color(value);
	if (color == -1)
		return (0);
	if (type == 'F')
		game->floor_color = color;
	else if (type == 'C')
		game->ceiling_color = color;
	return (1);
}

int	parse_color(char *color_str)
{
	char	**split;
	int		color;
	int		r;
	int		g;
	int		b;

	split = ft_split(color_str, ',');
	if (!split || count_split(split) != 3)
	{
		free_split(split);
		return (-1);
	}
	r = atoi(split[0]);
	g = atoi(split[1]);
	b = atoi(split[2]);
	free_split(split);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	color = (r << 16) | (g << 8) | b;
	return (color);
}
