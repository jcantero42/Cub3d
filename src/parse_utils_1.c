/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:08:23 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 14:08:25 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	get_max_len(t_game *game)
{
	int	i;
	int	max;
	int	len;

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
