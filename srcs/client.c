/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:37 by jeonscho          #+#    #+#             */
/*   Updated: 2023/01/16 17:23:26 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	usage(char *usg)
{
	ft_printf("%s\n", usg);
	exit(EXIT_FAILURE);
}

static void	send_message(int pid, char msg)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (kill(pid, ft_ternary(msg & (128 >> bit++), SIGUSR2, SIGUSR1)) < 0)
			usage(ERR);
		else
			usleep(INTERVAL);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3 || ft_isnum(argv[1]) == FALSE)
		usage(USG);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		usage(ZER);
	msg = argv[2];
	ft_printf("\e[1;36mClient PID:\033[1;0m %d\n", getpid());
	send_message(pid, 0);
	while (*msg)
		send_message(pid, *msg++);
	send_message(pid, 0);
	return (0);
}
