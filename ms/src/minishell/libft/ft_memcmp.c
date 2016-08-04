/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:22:25 by jpepin            #+#    #+#             */
/*   Updated: 2015/11/30 08:36:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t;
	unsigned char	*u;
	size_t			i;

	i = 0;
	t = (unsigned char*)s1;
	u = (unsigned char*)s2;
	if (t == NULL || u == NULL)
		return (0);
	else
	{
		while (t[i] == u[i] && i < n)
			i++;
		if (i != n)
			return (t[i] - u[i]);
		else
			return (0);
	}
}
