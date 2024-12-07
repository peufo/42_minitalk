/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:51 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 22:10:12 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

static int	add_next_digit(const char **str, int n)
{
	int	digit;

	if (!**str || !is_digit(**str))
		return (n);
	digit = **str - '0';
	(*str)++;
	return (add_next_digit(str, n * 10 + digit));
}

int	ft_atoi_ptr(const char **str)
{
	return (add_next_digit(str, 0));
}
