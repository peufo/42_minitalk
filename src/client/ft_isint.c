/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:53:41 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/07 18:20:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char	is_space(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return len;
}

static int	ft_isover(char *str, char *limit)
{
	int		limit_len;
	int		str_len;

	limit_len = ft_strlen(limit);
	str_len = ft_strlen(str);
	if (str_len < limit_len)
		return (0);
	if (str_len > limit_len)
		return (1);
	while (*limit)
	{
		if (*str > *limit)
			return (1);
		if (*str < *limit)
			return (0);
		str++;
		limit++;
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isint(char *str)
{
	short	sign;

	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign -= (*(str++) == '-') * 2;
	while (*str == '0')
		str++;
	if (sign == 1)
	{
		if (ft_isover(str, "2147483647"))
			return (0);
	}
	else
	{
		if (ft_isover(str, "2147483648"))
			return (0);
	}
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}