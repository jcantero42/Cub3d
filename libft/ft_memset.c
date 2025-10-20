/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:10:00 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 08:58:22 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	char	*str;
//
// 	str = (char *)malloc(20 * sizeof(char));
// 	if (!str)
// 		return (1);
// 	ft_memset(str, '0', 19);
// 	str[19] = '\0';
// 	printf("%s\n", str);
// 	return (0);
// }
