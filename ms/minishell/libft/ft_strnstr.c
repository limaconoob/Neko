/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 04:08:43 by jpepin            #+#    #+#             */
/*   Updated: 2015/12/11 21:18:47 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && n > 0)
		{
			i = 0;
			while (*(s1 + i) == s2[i] && *(s1 + i) && s2[i] && (n - i) > 0)
				i++;
			if (s2[i] == '\0')
				return ((char*)s1);
			n--;
			s1++;
		}
		return (NULL);
	}
	else
		return (NULL);
}
