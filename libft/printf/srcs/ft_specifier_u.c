/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:41:50 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:29:17 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_u(va_list *arg_ptr)
{
	char	*string;
	int		length;
	ssize_t	check;

	string = ft_utoa_base(va_arg(*arg_ptr, unsigned int), DEC);
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
