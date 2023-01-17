/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:11:01 by jeonscho          #+#    #+#             */
/*   Updated: 2023/01/17 15:44:48 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>

# include "../libft/libft.h" 
# include "../libft/printf/includes/ft_printf.h"

# define INTERVAL 50

typedef struct sigaction	t_sigaction;

# define USG "\033[1;32m----------------------------------------------------\
	\nUsage:\033[1;0m ./client <PID> <MESSAGE>        \
	\n\033[1;32m->\033[1;0m <PID>\t Server PID                  \
	\n\033[1;32m->\033[1;0m <MESSAGE>\t Message to be sent to Server.\
	\nIf you want to send message with multiple words, \
	\nthen use \033[1;31mdouble quotation marks\033[1;0m.\
	\n\033[1;32m----------------------------------------------------\033[1;0m"
# define ZER "\033[1;32mUsage:\033[1;0m <PID> can't be 0. Type server PID"
# define ERR "\033[1;32mERROR\033[1;0m while trying to send signal. \
	\ncheck PID of server first. \
	\nIf PID is right, then something wrong with kill fucntion."

#endif
