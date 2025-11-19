/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcantero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:08:34 by jcantero          #+#    #+#             */
/*   Updated: 2025/11/11 14:08:35 by jcantero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
