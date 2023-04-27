/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:20:39 by jaeheele          #+#    #+#             */
/*   Updated: 2023/04/28 01:02:33 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(const char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_putstr("0x") + \
		ft_puthex(va_arg(ap, unsigned long long), 'x'));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rslt;

	if (!(format))
		return (-1);
	rslt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			rslt += ft_print_arg(*format, ap);
		}
		else
			rslt += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (rslt);
}
