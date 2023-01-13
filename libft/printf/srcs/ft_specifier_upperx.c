/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_upperx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:42:09 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:29:28 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_upperx(va_list *arg_ptr)
{
	char	*string;
	int		length;
	int		i;
	ssize_t	check;

	i = -1;
	string = ft_utoa_base(va_arg(*arg_ptr, unsigned int), HEX);
	if (!string)
		return (-1);
	length = ft_strlen_printf(string);
	while (string[++i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
	check = ft_putstr_i(string);
	if (string)
		free(string);
	if (check == -1)
		return (-1);
	return (length);
}
