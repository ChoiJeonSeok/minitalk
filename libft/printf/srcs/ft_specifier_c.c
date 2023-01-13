/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:35:34 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/16 14:27:02 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_c(va_list *arg_ptr)
{
	ssize_t	check;

	check = ft_putchar_i(va_arg(*arg_ptr, int));
	if (check == -1)
		return (-1);
	return (1);
}
