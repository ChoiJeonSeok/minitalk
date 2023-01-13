/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:29 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:28:42 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_d(va_list *arg_ptr)
{
	char	*string;
	int		length;
	ssize_t	check;

	string = ft_itoa_printf(va_arg(*arg_ptr, int));
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
