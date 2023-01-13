/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:27:55 by jeonscho          #+#    #+#             */
/*   Updated: 2022/08/17 16:28:07 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	counts;

	i = 0;
	counts = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			counts++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counts);
}

static char	*ft_word(char const *s, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = 0;
	while (s[i] && (s[i] != c))
	{
		len_word++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_freeall(char **str, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(str[k++]);
	free(str);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			str[i++] = ft_word(s, c);
			if (!str[i - 1])
			{
				ft_freeall(str, i - 1);
				return (0);
			}
		}
		while (*s && (*s != c))
			s++;
	}
	str[i] = 0;
	return (str);
}
