/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:06:52 by marcolop          #+#    #+#             */
/*   Updated: 2024/05/08 16:40:27 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_pow(long int base, size_t exp)
{
	long int	n;

	if (exp == 0)
		return (1);
	n = base;
	while (--exp)
		n *= base;
	return (n);
}

char	*ft_itoa(int n)
{
	int		val;
	size_t	digit;
	char	*str;

	digit = 1;
	while (n / ft_pow(10, digit))
		digit++;
	val = 1;
	if (n < 0)
		val *= -1;
	if (n < 0)
		digit++;
	str = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (--digit)
	{
		str[digit] = (char)(val * (n % 10) + '0');
		n /= 10;
	}
	if (val == 1)
		str[digit] = (char)((n % 10) + '0');
	else
		str[0] = '-';
	return (str);
}
