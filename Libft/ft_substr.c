/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:24:09 by jaeheele          #+#    #+#             */
/*   Updated: 2023/01/18 17:42:56 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	index = ft_strlen(s + start);
	if (index >= len)
		index = len;
	result = malloc(sizeof(char) * (index + 1));
	if (!(result))
		return (0);
	ft_strlcpy(result, s + start, index + 1);
	return (result);
}
