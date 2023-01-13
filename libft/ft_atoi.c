/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:00:05 by jeonscho          #+#    #+#             */
/*   Updated: 2023/01/10 14:53:50 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitesp(const char *str, size_t *i)
{
	int		sign;
	size_t	k;

	k = 0;
	sign = 1;
	while ((str[k] >= 9 && str[k] <= 13) || (str[k] == 32))
		k++;
	if ((str[k] == 43 || str[k] == 45) && str[k])
	{
		if (str[k] == 45)
			sign *= -1;
		k++;
	}
	*i = k;
	return (sign);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	i = 0;
	sign = ft_whitesp(str, &i);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		if (nbr > 2147483647 && sign == 1)
			return (2147483647);
		if (nbr > 2147483647 && sign == -1)
			return (-2147483648);
		i++;
	}
	return (sign * nbr);
}
