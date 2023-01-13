/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:41:16 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/16 14:37:57 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_percent(va_list *arg_ptr)
{
	ssize_t	check;

	(void)*arg_ptr;
	check = ft_putchar_i('%');
	if (check == -1)
		return (-1);
	return (1);
}
