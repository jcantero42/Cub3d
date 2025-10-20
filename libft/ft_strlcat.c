/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:37:32 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/05 17:41:33 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tried_str_len;

	i = 0;
	j = 0;
	tried_str_len = 0;
	while (dest[i] != '\0')
		i++;
	while (src[tried_str_len] != '\0')
		tried_str_len++;
	if (size <= i)
		tried_str_len += size;
	else
		tried_str_len += i;
	while ((i + 1) < size && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (tried_str_len);
}

// int	 main(void)
// {
// 	 char	dest[15] = "Esto es ";
// 	 char	src[] = "una prueba";
// 	 int			 returned_value;
//
// 	 returned_value = ft_strlcat(dest, src, 15);
// 	 printf("Returned value: %d\n", returned_value);
// 	 printf("String: %s\n", dest);
// 	 return (0);
// }
