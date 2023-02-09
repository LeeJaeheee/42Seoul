/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:10:19 by jaeheele          #+#    #+#             */
/*   Updated: 2022/11/25 16:23:10 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l_len;
	size_t	b_len;
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	l_len = ft_strlen(needle);
	b_len = ft_strlen(haystack);
	if (b_len < l_len || len < l_len)
		return (0);
	if (b_len > len)
		size = len;
	else
		size = b_len;
	while (size-- >= l_len)
	{
		if (ft_memcmp(haystack, needle, l_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
