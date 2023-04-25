/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:20:39 by jaeheele          #+#    #+#             */
/*   Updated: 2023/04/25 21:48:31 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(const char **format, va_list args)
{
	int	s_len;

	s_len = 0;
	if (**format == 's')
		s_len += ft_putstr(va_arg(args, char *));
	else if (**format == 'd' || **format == 'i')
		s_len += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		s_len += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		s_len += ft_puthex(va_arg(args, unsigned int), **format);
	else if (**format == 'c')
		s_len += ft_putchar(va_arg(args, int));
	else if (**format == 'p')
	{
		s_len += ft_putstr("0x");
		s_len += ft_puthex((unsigned long long)va_arg(args, void *), 'x');
	}
	else if (**format == '%')
		s_len += ft_putchar('%');
	else
		s_len = -1;
	(*format)++;
	return (s_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		s_len;

	s_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s_len += ft_print_arg(&format, args);
		}
		else
			s_len += write(1, format++, 1);
	}
	va_end(args);
	return (s_len);
}
