/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:35:05 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 13:35:07 by jcantero         ###   ########.fr       */
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
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
	if (!game->no_texture || !game->so_texture || !game->we_texture
		|| !game->ea_texture || game->floor_color == -1
		|| game->ceiling_color == -1)
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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

int	parse_map(int fd, t_game *game)
{
	if (!create_map(fd, game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}

int	process_map_line(char *line, t_list **list, int *started)
{
	if (is_empty_line(line))
	{
		if (*started)
			return (0);
	}
	else
	{
		*started = 1;
		ft_lstadd_back(list, ft_lstnew(ft_strdup(line)));
	}
	return (1);
}

int	create_map(int fd, t_game *game)
{
	char	*line;
	int		started;
	t_list	*list;

	started = 0;
	list = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_map_line(line, &list, &started))
		{
			ft_lstclear(&list, free);
			return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!list)
		return (0);
	game->map = list_to_array(list, game);
	ft_lstclear(&list, free);
	if (!game->map)
		return (0);
	return (1);
}

int	valid_map(t_game *game)
{
	if (!trim_map_lines(game))
		return (0);
	if (!normalize_lines(game))
		return (0);
	if (!check_elements(game))
		return (0);
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;
	int	p_count;

	i = -1;
	p_count = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1'
				|| game->map[i][j] == ' ')
				continue ;
			else if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				assign_dir_and_pos(game, i, j, &p_count);
			else
				return (0);
		}
	}
	if (p_count != 1)
		return (0);
	return (1);
}

void	assign_dir_and_pos(t_game *game, int i, int j, int *p_count)
{
	if (game->map[i][j] == 'N')
		game->start_direction = NORTH;
	if (game->map[i][j] == 'S')
		game->start_direction = SOUTH;
	if (game->map[i][j] == 'E')
		game->start_direction = EAST;
	if (game->map[i][j] == 'W')
		game->start_direction = WEST;
	game->px = j;
	game->py = i;
	game->map[i][j] = '0';
	(*p_count)++;
}

int	normalize_lines(t_game *game)
{
	int		i;
	int		max_len;
	int		len;
	char	*spaces;
	char	*normalized;

	i = -1;
	max_len = get_max_len(game);
	i = -1;
	while (game->map[++i])
	{
		len = ft_strlen(game->map[i]);
		if (len == max_len)
			continue ;
		spaces = create_spaces(max_len - len);
		if (!spaces)
			return (0);
		normalized = ft_strjoin(game->map[i], spaces);
		free(spaces);
		if (!normalized)
			return (0);
		free(game->map[i]);
		game->map[i] = normalized;
	}
	return (1);
}

int	get_max_len(t_game *game)
{
	int	i;
	int max;
	int len;

	i = -1;
	max = 0;
	while (game->map[++i])
	{
		len = ft_strlen(game->map[i]);
		if (len > max)
			max = len;
	}
	game->width = max;
	return (max);
}

char	*create_spaces(int n)
{
	int		i;
	char	*spaces;

	spaces = malloc(sizeof(char) * (n + 1));
	if (!spaces)
		return (NULL);
	i = -1;
	while (++i < n)
		spaces[i] = ' ';
	spaces[i] = '\0';
	return (spaces);
}

int	is_config_line(char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n\t");
	if (!trimmed)
		return (0);
	if (!ft_strncmp(trimmed, "NO ", 3) || !ft_strncmp(trimmed, "SO ", 3)
		|| !ft_strncmp(trimmed, "WE ", 3) || !ft_strncmp(trimmed, "EA ", 3)
		|| !ft_strncmp(trimmed, "F ", 2) || !ft_strncmp(trimmed, "C ", 2))
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**list_to_array(t_list *list, t_game *g)
{
	char	**map;
	int		count;
	int		i;
	t_list	*temp;

	i = 0;
	count = 0;
	temp = list;
	while (temp)
	{
		++count;
		temp = temp->next;
	}
	map = malloc(sizeof(char *) * (count + 1));
	g->height = count;
	if (!map)
		return (NULL);
	while (list)
	{
		map[i] = ft_strdup((char *)list->content);
		++i;
		list = list->next;
	}
	map[i] = NULL;
	return (map);
}

int	trim_map_lines(t_game *game)
{
	int		i;
	char	*trimmed;

	i = -1;
	while (game->map[++i])
	{
		trimmed = ft_strtrim(game->map[i], "\n");
		if (!trimmed)
			return (0);
		free(game->map[i]);
		game->map[i] = trimmed;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
