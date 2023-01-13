/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:14:22 by jeonscho          #+#    #+#             */
/*   Updated: 2022/12/22 21:28:26 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr_i(char *string)
{
	ssize_t	check;

	if (!string)
		return (0);
	check = write(1, string, ft_strlen_printf(string));
	return (check);
}
