#include "../inc/cub3d.h"

int	parse_file(char	*filename, t_game *game)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!parse_config(fd, game))
		return (0);
	return (1);
}


int	parse_config(int fd, t_game *game)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!parse_config_line(line, game))
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

int parse_config_line(char *line, t_game *game)
{
    char    **split;
    char    *trimmed;
    int     color;

	trimmed = ft_strtrim(line, " \n\t");
	if (!trimmed)
		return (0);
	split = ft_split(trimmed, ' ');
	free(trimmed);
    if (!split || count_split(split) != 2)
        return (free_split(split), 0);
    if (ft_strcmp(split[0], "NO") == 0)
        game->no_texture = ft_strdup(split[1]);
    else if (ft_strcmp(split[0], "SO") == 0)
        game->so_texture = ft_strdup(split[1]);
    else if (ft_strcmp(split[0], "EA") == 0)
        game->ea_texture = ft_strdup(split[1]);
    else if (ft_strcmp(split[0], "WE") == 0)
        game->we_texture = ft_strdup(split[1]);
    else if (ft_strcmp(split[0], "F") == 0)
    {
        color = parse_color(split[1]);
        if (color == -1)
            return (free_split(split), 0);
        game->floor_color = color;
    }
    else if (ft_strcmp(split[0], "C") == 0)
    {
        color = parse_color(split[1]);
        if (color == -1)
            return (free_split(split), 0);
        game->ceiling_color = color;
    }
    else
        return (free_split(split), 0);
    return (free_split(split), 1);
}

void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int	config_is_complete(t_game *game)
{
	if (!game->no_texture || !game->so_texture || !game->we_texture || !game->ea_texture ||
		game->floor_color == -1 ||game->ceiling_color == -1)
		return (0);
	return (1);
}

int ft_strcmp(const char *s1, const char *s2) 
{
    
	while (*s1 && (*s1 == *s2)) 
	{
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
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

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}