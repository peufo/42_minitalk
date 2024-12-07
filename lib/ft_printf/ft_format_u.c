/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:35:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/23 00:19:39 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_u(va_list *args, t_format *fm)
{
	char			str[11];
	int				str_len;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	str_len = ft_uitoa(str, n, "0123456789");
	if (fm->precision > str_len)
		return (ft_run_precision_unsigned(fm, str, str_len, NULL));
	if (!n && fm->is_precision_defined && !fm->precision)
		return ((void)ft_run(fm, ft_put_pad(str, 0, fm)));
	ft_run(fm, ft_put_pad(str, str_len, fm));
}
