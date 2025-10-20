/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:43:19 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 15:39:20 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*psrc;
	unsigned char		*pdst;

	psrc = (const unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (psrc > pdst)
	{
		i = 0;
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[] = "hola mundo";
//
// 	ft_memmove(str, str + 5, 5);
// 	printf("%s\n", str);
// 	return (0);
// }
