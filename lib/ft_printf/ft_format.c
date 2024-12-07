/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:17:09 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 21:20:26 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_formaters(t_formater	*formaters)
{
	unsigned char	index;

	index = 0;
	while (index < CHAR_MAX)
		formaters[index++] = NULL;
	formaters['c'] = format_c;
	formaters['s'] = format_s;
	formaters['p'] = format_p;
	formaters['d'] = format_di;
	formaters['i'] = format_di;
	formaters['u'] = format_u;
	formaters['x'] = format_x_lower;
	formaters['X'] = format_x_upper;
	formaters['%'] = format_percent;
}

static char	capture_flags(char c, t_format *format)
{
	if (c == '0')
		format->is_expand_zero = 1;
	else if (c == '#')
		format->is_prefix_hex = 1;
	else if (c == '-')
		format->is_padright = 1;
	else if (c == ' ' && format->sign_positive != '+')
		format->sign_positive = ' ';
	else if (c == '+')
		format->sign_positive = '+';
	else
		return (0);
	return (1);
}

static void	capture_precision(const char **str, t_format *format)
{
	if (**str != '.')
		return ;
	(*str)++;
	format->precision = ft_atoi_ptr(str);
	format->is_precision_defined = 1;
	format->is_expand_zero = 0;
	return ;
}

static void	init_format(const char **str, t_format *format)
{
	t_formater	formaters[CHAR_MAX];

	(*str)++;
	init_formaters(formaters);
	format->formater = NULL;
	format->sign_positive = '\0';
	format->precision = 0;
	format->put_count = 0;
	format->is_padright = 0;
	format->is_prefix_hex = 0;
	format->is_expand_zero = 0;
	format->is_precision_defined = 0;
	while (capture_flags(**str, format))
		(*str)++;
	format->width = ft_atoi_ptr(str);
	capture_precision(str, format);
	format->formater = formaters[(int)*(*str)++];
}

int	ft_handle_format(const char **str, va_list *args)
{
	t_format	format;

	init_format(str, &format);
	if (!format.formater)
		return (-1);
	format.formater(args, &format);
	return (format.put_count);
}
