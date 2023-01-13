/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:10:04 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/16 14:37:21 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_specifiers(t_specifier *specifiers)
{
	*specifiers++ = specifier_c;
	*specifiers++ = specifier_s;
	*specifiers++ = specifier_p;
	*specifiers++ = specifier_d;
	*specifiers++ = specifier_d;
	*specifiers++ = specifier_u;
	*specifiers++ = specifier_x;
	*specifiers++ = specifier_upperx;
	*specifiers++ = specifier_percent;
}

static int	ft_print(const char *format, va_list *arg_ptr, t_specifier sp[])
{
	int		specifier;
	ssize_t	length;
	ssize_t	check;

	length = 0;
	while (*format)
	{
		specifier = ft_strchr_i(FORMATS, *(format + 1));
		if (*format == DELIMITER && specifier != -1)
		{
			check = sp[ft_strchr_i(FORMATS, *(++format))](arg_ptr);
			if (check == -1)
				return (-1);
			length += check;
		}
		else
		{
			check = ft_putchar_i(*format);
			if (check == -1)
				return (-1);
			length++;
		}
		format++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	ssize_t		length;
	va_list		arg_ptr;
	t_specifier	specifiers[9];

	if (!format)
		return (-1);
	assign_specifiers(specifiers);
	va_start(arg_ptr, format);
	length = ft_print(format, &arg_ptr, specifiers);
	va_end(arg_ptr);
	return (length);
}
