/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:59:31 by jeonscho          #+#    #+#             */
/*   Updated: 2023/01/13 22:08:34 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

t_bool	ft_isnum(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}
