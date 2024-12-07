/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:18:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 22:10:00 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	next_digit(char *dest, unsigned long n, char *base, int base_len)
{
	if (n == 0)
		return (0);
	*(--dest) = base[n % base_len];
	return (1 + next_digit(dest, n / base_len, base, base_len));
}

static char	*get_end(char *dest, unsigned long n, int base_len)
{
	if (n == 0)
	{
		*dest = '\0';
		return (dest);
	}
	return (get_end(dest + 1, n / base_len, base_len));
}

static int	ft_is_valid_base(char *base)
{
	while (*base)
	{
		if (*base < ' '
			|| *base == 127
			|| *base == '+'
			|| *base == '-'
			|| ft_includes(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

int	ft_itoa_base(char *dest, long n, char *base, t_format *fm)
{
	int		base_len;
	char	*dest_end;

	base_len = ft_strlen_printf(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
	{
		*(dest++) = fm->sign_positive;
		*(dest++) = '0';
		*(dest++) = '\0';
		return (2);
	}
	if (n < 0)
	{
		*(dest++) = '-';
		dest_end = get_end(dest, -n, base_len);
		return (1 + next_digit(dest_end, -n, base, base_len));
	}
	else
	{
		*(dest++) = fm->sign_positive;
		dest_end = get_end(dest, n, base_len);
		return (1 + next_digit(dest_end, n, base, base_len));
	}
}

int	ft_uitoa(char *dest, unsigned long n, char *base)
{
	int		base_len;
	char	*dest_end;

	base_len = ft_strlen_printf(base);
	if (base_len < 2 || !ft_is_valid_base(base))
		return (-1);
	if (n == 0)
	{
		*(dest++) = '0';
		*(dest++) = '\0';
		return (1);
	}
	dest_end = get_end(dest, n, base_len);
	return (next_digit(dest_end, n, base, base_len));
}
