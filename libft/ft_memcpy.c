/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:18:56 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 08:55:02 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	if (!dst && !src)
		return (dst);
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[] = "hola mundo";
//
// 	ft_memcpy(str, str + 5, 5);
// 	printf("%s\n", str);
// 	return (0);
// }
