/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:30:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/08 01:45:41 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handle_signal(int signo, siginfo_t *info, void *ctx)
{
	struct sigaction	sig;
	struct sigaction	old;
	static unsigned char	c;
	static short			i;
	short					bit;

	(void)ctx;
	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO | SA_ONSTACK;
	sigaddset(&sig.sa_mask, signo);
	sigaction(signo, &sig, &old);
	bit = (signo - SIGUSR1) % 2;
	c = c << 1;
	c += bit;
	i++;
	//ft_printf("%d", bit);
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = '\0';
	}
	sigaction(signo, &old, NULL);
	kill(info->si_pid, signo);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("%d\n", getpid());
	
	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
