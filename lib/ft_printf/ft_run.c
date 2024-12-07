/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:59:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 21:25:47 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_run(t_format *fm, int put_result)
{
	if (put_result == -1)
		fm->put_count = -1;
	if (fm->put_count == -1)
		return (1);
	fm->put_count += put_result;
	return (0);
}

void	ft_run_precision_unsigned(
	t_format *fm,
	char *str,
	int str_len,
	char *prefix)
{
	int	padding;

	padding = fm->width - fm->precision;
	if (prefix)
		padding -= ft_strlen_printf(prefix);
	if (!fm->is_padright && ft_run(fm, ft_put_char_n(' ', padding)))
		return ;
	if (prefix && ft_run(fm, write(1, prefix, ft_strlen_printf(prefix))))
		return ;
	if (ft_run(fm, ft_put_padleft(str, str_len, fm->precision, '0')))
		return ;
	if (fm->is_padright)
		ft_run(fm, ft_put_char_n(' ', padding));
	return ;
}

void	ft_run_precision(t_format *fm, long n, char *str, int str_len)
{
	char	is_sign_print;
	int		padding;

	is_sign_print = (fm->sign_positive || n < 0);
	padding = fm->width - fm->precision - is_sign_print;
	if (!fm->is_padright && padding > 0)
		if (ft_run(fm, ft_put_char_n(' ', padding)))
			return ;
	if (ft_run(fm, ft_put_sign(n, fm)))
		return ;
	if (ft_run(fm, ft_put_padleft(str + 1, str_len - 1, fm->precision, '0')))
		return ;
	if (fm->is_padright && padding > 0)
		ft_run(fm, ft_put_char_n(' ', padding));
	return ;
}

void	ft_run_expand_zero(t_format *fm, long n, char *str, int str_len)
{
	if (ft_run(fm, ft_put_sign(n, fm)))
		return ;
	ft_run(fm, ft_put_pad(str + 1, str_len - 1, fm));
}
