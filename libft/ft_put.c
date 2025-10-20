/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:53:57 by marcolop          #+#    #+#             */
/*   Updated: 2024/07/19 13:17:09 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
	return (sizeof(char));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	else
	{
		while (str[i] != '\0')
		{
			write(STDOUT_FILENO, &str[i], sizeof(char));
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		cnt;
	char	digit;

	cnt = 0;
	if (n == -2147483648)
		cnt += write(STDOUT_FILENO, "-2147483648", 11);
	if ((n < 0) && (n != -2147483648))
	{
		cnt += write(STDOUT_FILENO, "-", sizeof(char));
		n *= -1;
	}
	if ((n > 9) && (n != -2147483648))
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	else if (n != -2147483648)
	{
		digit = n + '0';
		cnt += write(STDOUT_FILENO, &digit, 1);
	}
	return (cnt);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	digit;
	int		cnt;

	cnt = 0;
	if (n > 9)
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	else
	{
		digit = n + '0';
		cnt += write(STDOUT_FILENO, &digit, sizeof(char));
	}
	return (cnt);
}
