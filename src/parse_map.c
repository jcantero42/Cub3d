/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:08:08 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 14:08:13 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	parse_map(int fd, t_game *game)
{
	if (!create_map(fd, game))
		return (0);
	if (!valid_map(game))
		return (0);
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

int	valid_map(t_game *game)
{
	if (!trim_map_lines(game))
		return (0);
	if (!normalize_lines(game))
		return (0);
	if (!check_elements(game))
		return (0);
	if (!walled_map(game, game->px, game->py))
		return (0);
	restore_map(game, game->px, game->py);
	return (1);
}
