/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:39:33 by marcolop          #+#    #+#             */
/*   Updated: 2024/08/05 16:12:48 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1 * sizeof(char));
		if (str != NULL)
			str[0] = '\0';
		return (str);
	}
	if ((ft_strlen(s) - start) <= len)
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*str;
//
// 	str = "get sub";
// 	printf("%s\n", ft_substr(str, 4, 3));
// 	return (0);
// }
