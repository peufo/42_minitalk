/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:56:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/22 23:36:32 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			put_count;
	int			write_res;

	va_start(args, str);
	put_count = 0;
	while (*str && put_count > -1)
	{
		if (*str == '%')
			write_res = ft_handle_format(&str, &args);
		else
			write_res = write(1, str++, 1);
		if (write_res == -1)
		{
			put_count = -1;
			break ;
		}
		put_count += write_res;
	}
	va_end(args);
	return (put_count);
}
