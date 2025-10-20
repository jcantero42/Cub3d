/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:11:47 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 15:52:03 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	int				src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	while (src[i] != '\0' && dstsize > 1)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char	*str;
// 	char	str2[20];
//
// 	str = "hola caracola\n";
// 	ft_strlcpy(str2, str, 19);
// 	printf("%s", str2);
// 	return (0);
// }
