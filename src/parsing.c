#include "../inc/cub3d.h"


int	parse_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (parse_config_line(line, game))
		{	
			free(line);
			break;
		}
		free(line);
	}
	if (!config_is_complete(game))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	parse_config_line(char *line, t_game *game)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0])
		return(ft_freeup(split));
	if (ft_strcmp(split[0], "NO") == 0)
		game->no_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0)
		game->so_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0)
		game->ea_texture = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0)
		game->we_texture = ft_strdup(split[1]);
	/*else if (ft_strcmp(split[0], "F") == 0)
		game->floor_color = parse_color(split[1]);
	else if (ft_strcmp(split[0], "C") == 0)
		game->ceiling_color = parse_color(split[1]);*/
	else
		return (ft_freeup(split), 0);
	return (ft_freeup(split, 1));	
}


int	config_is_complete(game)
{
	if (!game->no_texture || !game->so_texture || !game->we_texture || !game->ea_texture ||
		game->floor_color == -1 || game->ceiling_color == -1)
		return (0);
	return (1);
}
