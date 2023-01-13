/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:51:28 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:26:25 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DELIMITER '%'
# define FORMATS "cspdiuxX%"
# define BIN 2
# define OCT 8
# define DEC 10
# define HEX 16

// define function pointer
typedef int	(*t_specifier)(va_list *);

// prototype of ft_printf
int		ft_printf(const char *format, ...);

// specifier functions for t_specifier
int		specifier_c(va_list *arg_ptr);
int		specifier_d(va_list *arg_ptr);
int		specifier_p(va_list *arg_ptr);
int		specifier_percent(va_list *arg_ptr);
int		specifier_s(va_list *arg_ptr);
int		specifier_u(va_list *arg_ptr);
int		specifier_upperx(va_list *arg_ptr);
int		specifier_x(va_list *arg_ptr);
int		ft_strchr_i(const char *s, int c);

// utils
char	*ft_utoa_base(unsigned long n, int base);
ssize_t	ft_putchar_i(char c);
ssize_t	ft_putstr_i(char *string);
char	*ft_itoa_printf(int n);
size_t	ft_strlen_printf(const char *s);

#endif
