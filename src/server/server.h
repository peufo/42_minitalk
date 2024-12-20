/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/09 12:31:14 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define _XOPEN_SOURCE 700
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stddef.h>
# include "ft_printf.h"

typedef struct s_message
{
	char	*content;
	char	*logger;
	int		len;
}	t_message;

void	*ft_calloc(size_t size);

#endif