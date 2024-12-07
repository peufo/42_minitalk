/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:14:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 21:25:47 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_s(va_list *args, t_format *fm)
{
	char	*str;
	char	str_null[7];
	int		str_len;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_strcpy(str_null, "(null)");
		str = str_null;
	}
	str_len = ft_strlen_printf(str);
	if (fm->is_precision_defined && fm->precision < str_len)
		fm->put_count = ft_put_pad(str, fm->precision, fm);
	else
		fm->put_count = ft_put_pad(str, str_len, fm);
}
