/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:08:33 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 21:38:17 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_di(va_list *args, t_format *fm)
{
	char	str[12];
	int		str_len;
	int		n;

	n = va_arg(*args, int);
	str_len = ft_itoa_base(str, n, "0123456789", fm);
	if (fm->is_expand_zero)
		return (ft_run_expand_zero(fm, n, str, str_len));
	if (fm->precision >= str_len)
		return (ft_run_precision(fm, n, str, str_len));
	if (!n && fm->is_precision_defined && !fm->precision)
		return ((void)ft_run(fm, ft_put_pad(str, !!fm->sign_positive, fm)));
	if (!fm->sign_positive && n >= 0)
		return ((void)ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm)));
	ft_run(fm, ft_put_pad(str, str_len, fm));
}
