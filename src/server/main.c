/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:30:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/08 18:38:03 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"


int	terminate(char *error)
{
	if (!error)
		return (0);
	ft_printf("Error: %s\n", error);
	exit(1);
}

void	ensure_msg_len(t_message *msg)
{
	char	*new;

	if (!msg->len)
	{
		msg->len = 1;
		msg->content = malloc(msg->len + 1);
		msg->logger = msg->content;
		if (!msg->content)
			terminate("Malloc failed");
	}
	if (msg->logger - msg->content == msg->len - 1)
	{
		msg->len *= 2;
		new = malloc(msg->len + 1);
		if (!new)
		{
			free(msg->content);
			terminate("Malloc failed");
		}
		ft_strcpy(new, msg->content);
		msg->logger = new + (msg->logger - msg->content);
		free(msg->content);
		msg->content = new;
	}
}

void	next_char(char c)
{
	static t_message	msg;

	ensure_msg_len(&msg);
	*(msg.logger++) = c;
	if (c == '\0')
	{
		ft_printf("%s", msg.content);
		free(msg.content);
		msg.len = 0;
	}
}

void	handle_signal(int signo, siginfo_t *info, void *ctx)
{
	static unsigned char	c;
	static short			i;
	short					bit;

	(void)ctx;
	(void)info;
	(void)c;
	(void)i;
	(void)bit;
	bit = (signo - SIGUSR1) % 2;
	c <<= 1;
	c += bit;
	i++;
	if (i == 8)
	{
		next_char(c);
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
