/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:09:43 by jaeheele          #+#    #+#             */
/*   Updated: 2023/01/19 14:20:24 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	find;

	s1 = (unsigned char *)s;
	find = (unsigned char)c;
	while (n--)
	{
		if (*s1 == find)
			return ((void *)s1);
		s1++;
	}
	return ((void *)0);
}
