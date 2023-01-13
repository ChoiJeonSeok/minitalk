/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:19:34 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:16:26 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_utoa(unsigned long n)
{
	char	c;

	c = (char)n + '0';
	if (c > '9')
		c += 39;
	return (c);
}

static size_t	ft_utoa_len(unsigned long n, int base)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

char	*ft_utoa_base(unsigned long n, int base)
{
	char	*string;
	size_t	length;

	length = ft_utoa_len(n, base) + 1;
	string = (char *)malloc(sizeof(char) * length);
	if (!string)
		return (NULL);
	string[--length] = '\0';
	while (length > 0)
	{
		string[--length] = ft_get_utoa(n % base);
		n = n / base;
	}
	return (string);
}
