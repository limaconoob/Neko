/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 03:44:47 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/11 21:07:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (*s)
			s++;
		if ((char)c != 0)
			s--;
		while (*s && *s != (char)c)
			s--;
		if (*s == (char)c)
			return ((char*)s);
	}
	return (NULL);
}
