/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonscho <jeonscho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:31 by jeonscho          #+#    #+#             */
/*   Updated: 2023/01/16 19:51:53 by jeonscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sigusr(int signal)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	bit++;
	c <<= 1;
	if (signal == SIGUSR2)
		c++;
	if (bit == 8)
	{
		if (c)
			write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	t_sigaction	sa;
	sigset_t	mask;

	sigemptyset(&mask);
	sa.sa_flags = 0;
	sa.sa_mask = mask;
	sa.sa_handler = handle_sigusr;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error. sigaction failed."));
	ft_printf("\e[1;36mPID:\033[1;0m %d\n", getpid());
	while (TRUE)
		pause();
	return (0);
}
