/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 03:17:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 09:23:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../sh1.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (s1 && (!(s2 = (char*)malloc(ft_strlen(s1) + 1))))
		shell_error(Malloc, "s2 in ft_strdup");
	else if (!s1 && (!(s2 = (char*)malloc(1))))
		shell_error(Malloc, "s2 in ft_strdup");
	if (s1)
	{
		i = 0;
		while (s1[i])
		{
			s2[i] = (char)s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		*s2 = 0;
	return (s2);
}
