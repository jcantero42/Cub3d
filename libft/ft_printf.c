/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:16:29 by marcolop          #+#    #+#             */
/*   Updated: 2024/07/23 11:49:37 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convers(char *format, int i, va_list *args, int *cnt)
{
	uintptr_t	hex;

	if (format[i + 1] == 's')
		*cnt += (ft_putstr(va_arg(*args, char *)) - 2);
	else if (format[i + 1] == 'c')
		*cnt += (ft_putchar(va_arg(*args, int)) - 2);
	else if ((format[i + 1] == 'i') || (format[i + 1] == 'd'))
		*cnt += (ft_putnbr(va_arg(*args, int)) - 2);
	else if (format[i + 1] == 'u')
		*cnt += (ft_putnbr_unsigned(va_arg(*args, unsigned int)) - 2);
	else if (format[i + 1] == 'p')
		*cnt += (ft_putmem(va_arg(*args, void *)) - 2);
	else if (format[i + 1] == 'x')
	{
		hex = (uintptr_t)va_arg(*args, unsigned int);
		*cnt += (ft_puthex(hex, LOWERCASE) - 2);
	}
	else if (format[i + 1] == 'X')
	{
		hex = (uintptr_t)va_arg(*args, unsigned int);
		*cnt += (ft_puthex(hex, UPPERCASE) - 2);
	}
	else if (format[i + 1] == '%')
		*cnt -= ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;
	int		i;

	va_start(args, format);
	i = 0;
	cnt = 0;
	while (format[i] != '\0')
	{
		while ((format[i] != '%') && (format[i] != '\0'))
		{
			write(STDOUT_FILENO, &format[i], sizeof(char));
			i++;
		}
		if (format[i] == '\0' || format[i + 1] == '\0')
			break ;
		ft_convers((char *)format, i, &args, &cnt);
		i += 2;
	}
	va_end(args);
	return (i + cnt);
}
