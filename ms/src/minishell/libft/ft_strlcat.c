/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:24:45 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/04 09:18:16 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		stock;
	size_t		n;
	char		*d;
	char const	*s;

	d = dst;
	s = src;
	n = size;
	while (*d && n-- != 0)
		d++;
	stock = d - dst;
	n = size - stock;
	if (n == 0)
		return (stock + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (stock + s - src);
}
