/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:20:39 by jaeheele          #+#    #+#             */
/*   Updated: 2023/03/26 04:17:26 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion(const char **format, va_list args)
{
	int	done;

	done = 0;
	if (**format == 's')
		done += ft_putstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		done += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		done += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		done += ft_puthex(va_arg(args, unsigned int), **format);
	else if (**format == 'c')
		done += ft_putchar(va_arg(args, int));
	else if (**format == 'p')
	{
		done += ft_putstr("0x");
		done += ft_puthex((unsigned long long)va_arg(args, void *), 'x');
	}
	else if (**format == '%')
		done += ft_putchar('%');
	else
		done = -1;
	(*format)++;
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	done = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			done += print_conversion(&format, args);
		}
		else
			done += write(1, format++, 1);
	}
	va_end(args);
	return (done);
}
