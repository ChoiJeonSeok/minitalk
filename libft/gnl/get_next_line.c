/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:05:24 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 20:10:21 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(char *str, size_t len, ssize_t size)
{
	char	*tmp;

	if (!str)
		str = (char *)malloc(sizeof(char) * (size + 1));
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + size + 1));
		if (!tmp)
		{	
			free(str);
			return (NULL);
		}
		ft_strlcpy_gnl(tmp, str, len + 1);
		free(str);
		str = tmp;
		tmp = NULL;
	}
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_clean(char *buffer)
{
	size_t	i;
	char	*str;
	size_t	size;

	if (!buffer)
		return (NULL);
	str = NULL;
	i = 0;
	while (buffer[i] != '\n')
		i++;
	ft_strlcpy_gnl(buffer, &buffer[i + 1], BUFFER_SIZE - i);
	if (!*buffer)
		return (NULL);
	size = ft_strlen_gnl(buffer);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = ft_cpyline_gnl(str, buffer, 0);
	str = ft_realloc(str, i, 0);
	return (str);
}

static char	*ft_read(int fd, char *buffer, char *str)
{
	ssize_t	size;
	size_t	i;

	if (!str)
		i = 0;
	else
		i = ft_strlen_gnl(str);
	size = read(fd, buffer, BUFFER_SIZE);
	while (size > 0)
	{
		buffer[size] = '\0';
		str = ft_realloc(str, i, size);
		if (!str)
			return (NULL);
		i = ft_cpyline_gnl(str, buffer, i);
		str = ft_realloc(str, i, 0);
		if (ft_strchr_gnl(str, '\n') || !str)
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (size == -1 && str)
		free(str);
	if ((size == 0 && !str) || (size == -1) || (!str))
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	if (ft_strchr_gnl(buffer, '\n'))
	{
		str = ft_clean(buffer);
		if (ft_strchr_gnl(str, '\n'))
			return (str);
	}
	line = ft_read(fd, buffer, str);
	return (line);
}
