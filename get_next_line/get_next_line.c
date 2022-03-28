/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:57:16 by hhamdy            #+#    #+#             */
/*   Updated: 2022/02/19 15:58:20 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define BUFFER_SIZE 1

static int	index_line(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i])
	{
		if (p[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static void	get_rest(char **save, char **line, ssize_t end, char **tmp)
{
	if (end == 0 && !ft_strchr(*save, '\n'))
	{
		*line = ft_strdup(*save);
		*save = 0;
	}
	else
	{
		*line = ft_substr(*save, 0, index_line(*save, '\n') + 1);
		*save = ft_strdup(*save + index_line(*save, '\n') + 1);
	}
	ft_free(*tmp);
	if (**line == '\0')
	{
		ft_free(*line);
		*line = NULL;
	}
}

static void	get_line(int fd, char **save, char *buff, char **line)
{
	ssize_t	end;
	char	*tmp;

	end = 1;
	buff[0] = '\0';
	while (end != 0 && (!ft_strchr(buff, '\n')))
	{
		end = read(fd, buff, BUFFER_SIZE);
		buff[end] = '\0';
		tmp = *save;
		*save = ft_strjoin(tmp, buff);
		ft_free(tmp);
	}
	ft_free(buff);
	tmp = *save;
	get_rest(save, line, end, &tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	char		*line;

	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) == -1)
	{
		ft_free(buff);
		return (NULL);
	}
	if (!save)
		save = ft_strdup("");
	get_line(fd, &save, buff, &line);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("get_next_line_utils.c", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// }
