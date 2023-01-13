/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:19:42 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:26:47 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_printf(int n)
{
	int			len;
	int			sign;
	long long	nb;
	char		*str;

	nb = n;
	sign = 1;
	len = ft_count_digit(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		sign = -1;
		nb *= -1;
	}
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
