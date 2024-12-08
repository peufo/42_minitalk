/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:30:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/08 02:23:36 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handle_signal(int signo, siginfo_t *info, void *ctx)
{
	static unsigned char	c;
	static short			i;
	short					bit;

	(void)ctx;
	bit = (signo - SIGUSR1) % 2;
	c <<= 1;
	c += bit;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = '\0';
	}
	kill(info->si_pid, signo);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d\n", getpid());
	
	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
