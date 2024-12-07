/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:56:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 23:50:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_p(va_list *args, t_format *fm)
{
	unsigned long	n;
	char			str[24];
	int				str_len;

	n = va_arg(*args, unsigned long);
	str[0] = '0';
	str[1] = 'x';
	str_len = ft_uitoa(str + 2, n, "0123456789abcdef");
	ft_run(fm, ft_put_pad(str, str_len + 2, fm));
}
