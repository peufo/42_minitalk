/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:24:57 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/09 12:31:05 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*ft_calloc(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(size);
	if (!ptr)
		return (0);
	while (size)
		ptr[--size] = 0;
	return ((void *)(ptr));
}