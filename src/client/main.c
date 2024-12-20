/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:11:42 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/09 14:04:41 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	terminate(char *error)
{
	if (!error)
		return (0);
	ft_printf("Error: %s\n", error);
	return (1);
}

static short	get_next_bit(char **msg)
{
	static short	i;
	unsigned char	c;
	short			bit;

	if (!*msg)
		return (-1);
	if (i == 8)
	{
		if (**msg == '\0')
		{
			*msg = NULL;
			return (-1);
		}
		i = 0;
		(*msg)++;
	}
	c = **msg;
	bit = (c >> (7 - i)) & 1;
	i++;
	return (bit);
}

static void	send_next_bit(int process_id, char **message)
{
	static char		**msg;
	static int		pid;
	short			bit;

	if (process_id)
		pid = process_id;
	if (message)
		msg = message;
	bit = get_next_bit(msg);
	if (bit == 0)
		kill(pid, SIGUSR1);
	if (bit == 1)
		kill(pid, SIGUSR2);
	return ;
}

static void	handle_response(int signo, siginfo_t *info, void *ctx)
{
	(void)signo;
	(void)info;
	(void)ctx;
	send_next_bit(0, NULL);
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	char				*msg;
	int					process_id;

	if (ac != 3)
		return (terminate("Bad arguments (int server_pid, char *message)"));
	if (!ft_isint(av[1]))
		return (terminate("server_pid is not an integer"));
	process_id = ft_atoi(av[1]);
	msg = av[2];
	if (!process_id)
		return (terminate("server_pid can't be set to 0"));
	sig.sa_sigaction = handle_response;
	sig.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_next_bit(process_id, &msg);
	while (msg)
		pause();
	return (0);
}
