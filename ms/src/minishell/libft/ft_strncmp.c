/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 03:00:11 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/10 13:28:33 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2 && n)
		{
			s1++;
			s2++;
			n--;
		}
		if (n != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else
			return (0);
	}
	else
		return (0);
}
