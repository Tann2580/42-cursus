/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanshen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:57:14 by yanshen           #+#    #+#             */
/*   Updated: 2024/12/29 16:33:38 by yanshen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_byte(int fd, char *buf, char *remain)
{
	ssize_t	read_byte;
	char	*temp;

	read_byte = read(fd, buf, BUFFER_SIZE);
	if (read_byte < 0)
		return (NULL);
	if (read_byte == 0)
	{
		if (*remain == '\0')
			return (NULL);
	}
	buf[read_byte] = '\0';
	temp = ft_strjoin(remain, buf);
	if (!temp)
	{
		free(remain);
		return (NULL);
	}
	free(remain);
	remain = temp;
	return (remain);
}

char	*ft_read(int fd, char *remain)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!remain)
		remain = ft_strdup("");
	while (1)
	{
		remain = ft_read_byte(fd, buf, remain);
		if (!remain)
		{
			free(buf);
			return (NULL);
		}
		if (ft_strchr(remain, '\n'))
			break ;
	}
	free(buf);
	return (remain);
}

char	*ft_line(char *remain)
{
	char	*line;
	char	*position;

	position = ft_strchr(remain, '\n');
	if (position)
		line = ft_substr(remain, 0, position - remain + 1);
	else
		line = ft_strdup(remain);
	return (line);
}

char	*ft_next(char *remain)
{
	char	*temp;
	char	*position;

	position = ft_strchr(remain, '\n');
	if (position)
	{
		temp = ft_strdup(position + 1);
		free(remain);
		remain = temp;
	}
	else
	{
		free(remain);
		return (NULL);
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;

	if (fd < 0)
		return (NULL);
	remain = ft_read(fd, remain);
	if (!remain)
		return (NULL);
	line = ft_line(remain);
	remain = ft_next(remain);
	return (line);
}
/*
#include <stdio.h>

int	main()
	int	fd = open("test.txt", O_RDONLY);
	char	*line;
	printf("fd is %d\n", fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
读1024个字符 和前面回车后续内容拼接
检查拼接内容是否有回车
是 --> 记录回车位置，保存回车后续位置 返回line
否 --> 继续读1024个字符*/
