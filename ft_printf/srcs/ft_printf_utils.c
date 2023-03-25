/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:21:43 by jaeheele          #+#    #+#             */
/*   Updated: 2023/03/26 00:24:46 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	printed_len;

	i = 0;
	printed_len = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		printed_len += write(1, &str[i], 1);
		i++;
	}
	return (printed_len);
}

int	ft_putnbr(int nb)
{
	int	printed_len;

	printed_len = 0;
	if (nb == -2147483648)
		printed_len += write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
			printed_len += write(1, "-", 1) + ft_putnbr(nb * (-1));
		else
		{
			if (nb / 10 == 0)
			{
				nb = nb + '0';
				printed_len += write(1, &nb, 1);
			}
			else
			{
				printed_len += ft_putnbr(nb / 10) \
				+ ft_putnbr(nb % 10);
			}
		}
	}
	return (printed_len);
}

int	ft_putunbr(unsigned int nb)
{
	int	printed_len;

	printed_len = 1;
	if (nb / 10 > 0)
		printed_len += ft_putunbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (printed_len);
}

int	ft_puthex(unsigned long long num, char type)
{
	int		printed_len;
	char	*hex;

	printed_len = 1;
	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num >= 16)
		printed_len += ft_puthex(num / 16, type);
	ft_putchar(hex[num % 16]);
	return (printed_len);
}
