/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheele <jaeheele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:16:21 by jaeheele          #+#    #+#             */
/*   Updated: 2023/02/09 14:34:37 by jaeheele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_read(int fd, char *buf, char **str) //str 이차원으로 받아온 이유?
{
	ssize_t	i; //ssize_t?
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n')) //처음 읽어오거나 읽어놓은 버퍼에 개행존재X
	{
		i = read(fd, buf, BUFFER_SIZE); //에러 처리 해줘야됨(-1인 경우 널 리턴)
		while (i > 0) //i = 0이면?
		{
			buf[i] = 0; //마지막에 널문자
			if (!*str) // 메모리 할당 안돼있으니까
				*str = ft_substr(buf, 0, i); // malloc으로 str 생성하고 buf값 복사
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf); //여기서도 말록해서 새로운 공간 만드니까 tmp로 원래 공간 free하기 위해서
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
		//i = -1이어서 탈출한 경우 어떻게 에러처리할지 생각(버퍼 비우기)
	}
	free(buf);
}

static char	*gnl_process(char **str)
{
	size_t	i; //size_t로 바꾸기
	size_t	j; //size_t로 바꾸기
	char	*ret;
	char	*tmp;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n')) //파일 다읽어서 개행 없는 경우?
	{
		ret = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0; //이차원 포인터 프리?
		return (ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd 가능 범위
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); //\0때문?
	if (!buf) //널가드 사용 이유
		return (NULL);
	gnl_read(fd, buf, &str); // read에서 에러나서 null반환 처리
	return (gnl_process(&str));
}

