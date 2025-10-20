/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:56:46 by marcolop          #+#    #+#             */
/*   Updated: 2025/04/29 19:04:41 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash, char *buf)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (b_read == 0)
			return (stash);
		buf[b_read] = '\0';
		if (!stash)
			stash = gnl_strdup("");
		tmp = stash;
		stash = gnl_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (gnl_strchr(buf, '\n') != NULL)
			return (stash);
	}
	return (stash);
}

static char	*update_stash(char *line)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stash = gnl_substr(line, i + 1, gnl_strlen(&(line[i])));
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(stash);
		free(buf);
		stash = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = read_line(fd, stash, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = update_stash(line);
	return (line);
}
