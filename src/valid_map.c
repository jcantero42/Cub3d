/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:08:44 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 14:08:45 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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

void    free_map(char **map)
{
    int i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
