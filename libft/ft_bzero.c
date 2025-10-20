/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:06:01 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 08:59:50 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p = (unsigned char) '\0';
		p++;
		i++;
	}
	return ;
}

// int	main(void)
// {
// 	char	*str;
//
// 	str = (char *)malloc(20 * sizeof(char));
// 	if (!str)
// 		return (1);
// 	ft_bzero(str, 19);
// 	str[19] = '\0';
// 	printf("%s\n", str);
// 	return (0);
// }
