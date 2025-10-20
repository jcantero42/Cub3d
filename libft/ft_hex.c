/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:52:29 by marcolop          #+#    #+#             */
/*   Updated: 2024/07/22 12:10:00 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexletter(uintptr_t n, int case_flag, int cnt)
{
	char	digit;

	if (case_flag == LOWERCASE)
	{
		digit = n + 'a' - 10;
		cnt += write(STDOUT_FILENO, &digit, sizeof(char));
	}
	else if (case_flag == UPPERCASE)
	{
		digit = n + 'A' - 10;
		cnt += write(STDOUT_FILENO, &digit, sizeof(char));
	}
	return (cnt);
}

int	ft_puthex(uintptr_t n, int case_flag)
{
	char	digit;
	int		cnt;

	cnt = 0;
	if (n > 15)
	{
		cnt += ft_puthex(n / 16, case_flag);
		cnt += ft_puthex(n % 16, case_flag);
	}
	else
	{
		if (n < 10)
		{
			digit = n + '0';
			cnt += write(STDOUT_FILENO, &digit, sizeof(char));
		}
		else
		{
			cnt += ft_puthexletter(n, case_flag, cnt);
		}
	}
	return (cnt);
}

int	ft_putmem(void *mem)
{
	int	cnt;

	cnt = 0;
	if (!mem)
	{
		write(STDOUT_FILENO, "(nil)", 5);
		return (5);
	}
	write(STDOUT_FILENO, "0x", 2);
	cnt = ft_puthex((uintptr_t)mem, 1);
	return (cnt + 2);
}
