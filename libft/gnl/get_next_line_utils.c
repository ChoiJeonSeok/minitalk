/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:55:46 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 20:10:51 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strchr_gnl(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
		if (*str++ == (unsigned char)c)
			return ((char *)(str - 1));
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_gnl(src);
	if (size == 0)
		return (src_len);
	while (i < src_len && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_cpyline_gnl(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		dst[len++] = src[i++];
	if (src[i] == '\n')
		dst[len++] = '\n';
	dst[len] = '\0';
	i = ft_strlen_gnl(dst);
	return (i);
}
