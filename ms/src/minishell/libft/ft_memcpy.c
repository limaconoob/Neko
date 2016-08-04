/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 01:27:27 by jpepin            #+#    #+#             */
/*   Updated: 2015/11/28 22:36:53 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
