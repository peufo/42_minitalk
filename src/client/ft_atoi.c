/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:58:27 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/07 17:41:16 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	is_space(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		n;
	short	sign;

	n = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign -= (*(str++) == '-') * 2;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
		n = n * 10 + sign * (*(str++) - '0');
	return (n);
}