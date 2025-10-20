/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:07:50 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/06 05:33:53 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
//
// 	s1 = "hello";
// 	s2 = "world";
// 	printf("%d\n", ft_strncmp(s1, s2, 9));
// 	return (0);
// }
