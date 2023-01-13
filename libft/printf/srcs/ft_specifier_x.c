/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:42:21 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:29:37 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_x(va_list *arg_ptr)
{
	char	*string;
	int		length;
	ssize_t	check;

	string = ft_utoa_base(va_arg(*arg_ptr, unsigned int), HEX);
	if (!string)
		return (-1);
	length = ft_strlen_printf(string);
	check = ft_putstr_i(string);
	if (string)
		free(string);
	if (check == -1)
		return (-1);
	return (length);
}
