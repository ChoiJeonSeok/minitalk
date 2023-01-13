/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:38:45 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/16 14:27:32 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_zero(char *string)
{
	ssize_t	check;

	check = ft_putstr_i("0x0");
	free(string);
	if (check == -1)
		return (-1);
	return (3);
}	

int	specifier_p(va_list *arg_ptr)
{
	char	*string;
	ssize_t	check;

	string = ft_utoa_base((va_arg(*arg_ptr, unsigned long)), HEX);
	if (!string)
		return (-1);
	if (*string == '0')
		return (ft_zero(string));
	else if (string && *string)
	{
		check = ft_putstr_i("0x");
		if (check == -1)
		{
			free(string);
			return (-1);
		}
	}
	check = ft_putstr_i(string);
	if (check == -1)
	{
		free(string);
		return (-1);
	}
	free(string);
	return (2 + check);
}
