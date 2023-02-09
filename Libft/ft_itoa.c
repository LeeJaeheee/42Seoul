/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:03:35 by jaeheele          #+#    #+#             */
/*   Updated: 2023/01/19 17:03:48 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	ft_get_len(int num)
{
	int	len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		len;

	len = ft_get_len(n);
	if (n < 0)
		sign = 1;
	else
		sign = 0;
	result = (char *)malloc(len + 1);
	if (!(result))
		return (0);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
	}
	if (sign)
		result[0] = '-';
	return (result);
}
