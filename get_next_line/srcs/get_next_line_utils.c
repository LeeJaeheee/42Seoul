/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:45:49 by jaeheele          #+#    #+#             */
/*   Updated: 2023/03/10 17:43:59 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	size_t	len;
	char	*result;

	len = ft_strlen (s);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size--)
		result[size] = s[start + size];
	return (result);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*result;
	char	*p_result;
	char	*p_s1;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(result))
	{
		free(s1);
		return (NULL);
	}
	p_result = result;
	p_s1 = s1;
	while (*p_s1)
		*p_result++ = *p_s1++;
	while (*s2)
		*p_result++ = *s2++;
	*p_result = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	save;
	size_t			index;

	save = (unsigned char)c;
	index = 0;
	while (s[index])
	{
		if (s[index] == save)
			return ((char *)s + index);
		index++;
	}
	if (s[index] == save)
		return ((char *)s + index);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	index;

	if (!(s1))
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		dst[index] = s1[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
