/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/08 16:05:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
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