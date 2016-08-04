/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:51:48 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/11 20:48:20 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *dest;

	dest = s1;
	while (*dest)
		dest++;
	while (*s2 && n > 0)
	{
		*dest = *(char*)s2;
		dest++;
		s2++;
		n--;
	}
	*dest = '\0';
	return (s1);
}
