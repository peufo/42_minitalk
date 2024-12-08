/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/08 18:36:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define __USE_XOPEN_EXTENDED
# define _GNU_SOURCE
#include <bits/sigaction.h>
#include <asm-generic/signal-defs.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct s_message
{
	char	*content;
	char	*logger;
	int		len;
}	t_message;

#endif