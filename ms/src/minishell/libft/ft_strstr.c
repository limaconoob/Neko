/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 04:08:43 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/11 20:58:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char*)s1);
	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		while (*s1)
		{
			i = 0;
			while (*(s1 + i) == s2[i] && *(s1 + i) && s2[i])
				i++;
			if (s2[i] == '\0')
				return ((char*)s1);
			s1++;
		}
		return (NULL);
	}
	else
		return (NULL);
}
