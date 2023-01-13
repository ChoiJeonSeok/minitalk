/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:41:32 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:29:06 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_s(va_list *arg_ptr)
{
	char	*string;
	int		length;
	ssize_t	check;

	string = va_arg(*arg_ptr, char *);
	if (!string)
		string = "(null)";
	length = ft_strlen_printf(string);
	check = ft_putstr_i(string);
	if (check == -1)
		return (-1);
	return (length);
}
