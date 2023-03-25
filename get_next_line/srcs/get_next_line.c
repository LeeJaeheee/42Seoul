/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:16:21 by jaeheele          #+#    #+#             */
/*   Updated: 2023/03/10 17:43:28 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **p)
{
	free(*p);
	*p = NULL;
}

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		ft_free(temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen(ptr));
	free(*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr(temp, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free(temp, buf);
		if (!temp)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = ft_strdup("");
	if (!temp)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		ft_free(&temp);
		return (NULL);
	}
	temp = ft_read(temp, fd, buf);
	if (!temp)
		return (NULL);
	if (!*temp)
	{	
		ft_free(&temp);
		return (NULL);
	}
	return (ft_next(&temp));
}
