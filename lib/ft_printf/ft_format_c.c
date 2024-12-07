/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 23:50:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_c(va_list *args, t_format *fm)
{
	char	c;

	c = (char)va_arg(*args, int);
	ft_run(fm, ft_put_pad(&c, 1, fm));
}
