/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:59:58 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 19:53:40 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len != 0 && s[s_len] != (char)c)
		s_len--;
	if (s[s_len] == (char)c)
		return ((char *)s + s_len);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	k = 0;
	if (!*needle || haystack == needle)
		return ((char *)haystack);
	while (*(haystack + k) && len > 0)
	{
		i = 0;
		while ((haystack + k)[i] == needle[i] && i < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + k));
		}
		k++;
		len--;
	}
	return (NULL);
}
