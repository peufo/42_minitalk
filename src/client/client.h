/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/09 11:49:35 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define _XOPEN_SOURCE 700
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

int	ft_atoi(const char *str);
int	ft_isint(char *str);

#endif