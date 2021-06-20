/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:50:49 by sergey            #+#    #+#             */
/*   Updated: 2021/04/27 12:14:14 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;

	if (!dst || !src)
		return (0);
	counter = ft_strlen(src);
	if (!size)
		return (counter);
	while (((size--) > 1) && (*src))
		*(dst++) = *(src++);
	*dst = '\0';
	return (counter);
}
