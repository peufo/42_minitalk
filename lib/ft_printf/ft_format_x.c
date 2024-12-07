/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:38:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/23 00:26:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_x(va_list *args, t_format *fm, char *prefix, char *base)
{
	unsigned int	n;
	char			str[13];
	int				str_len;

	n = va_arg(*args, unsigned int);
	ft_strcpy(str, prefix);
	str_len = ft_uitoa(str + 2, n, base);
	if (fm->precision > str_len)
	{
		if (fm->is_prefix_hex && n > 0)
			return (ft_run_precision_unsigned(fm, str + 2, str_len, prefix));
		else
			return (ft_run_precision_unsigned(fm, str + 2, str_len, NULL));
	}
	if (fm->is_prefix_hex && n > 0)
	{
		if (!fm->is_expand_zero)
			return ((void)ft_run(fm, ft_put_pad(str, str_len + 2, fm)));
		if (ft_run(fm, write(1, prefix, 2)))
			return ;
		return ((void)ft_run(fm, ft_put_pad(str + 2, str_len, fm)));
	}
	if (!n && fm->is_precision_defined && !fm->precision)
		return ((void)ft_run(fm, ft_put_pad(str + 2, 0, fm)));
	ft_run(fm, ft_put_pad(str + 2, str_len, fm));
}

void	format_x_lower(va_list *args, t_format *fm)
{
	format_x(args, fm, "0x", "0123456789abcdef");
}

void	format_x_upper(va_list *args, t_format *fm)
{
	format_x(args, fm, "0X", "0123456789ABCDEF");
}
