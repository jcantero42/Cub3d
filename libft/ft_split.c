/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:32:49 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/07 09:39:18 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **set)
{
	int	i;

	i = 0;
	while (set[i] != NULL)
	{
		free(set[i]);
		i++;
	}
	free(set);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**ft_str_to_set(char const *s, char c, char **set)
{
	size_t	i;
	size_t	start;
	size_t	word;

	i = 0;
	start = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			set[word] = ft_substr(s, start, i - start + 1);
			if (!(set[word]))
			{
				ft_free(set);
				return (NULL);
			}
			word++;
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	set[word] = 0;
	return (set);
}

char	**ft_split(char const *s, char c)
{
	char	**set;

	if (!s)
		return (NULL);
	set = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!set)
		return (NULL);
	set = ft_str_to_set(s, c, set);
	return (set);
}
