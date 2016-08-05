/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 05:27:59 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/14 08:04:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../sh1.h"

/*
** Rückkehre Wert :
** strjoin rückgabt ein (char *) zuweisen mit malloc(3),
** dass mit beide Sätze eine Reihe erstellen.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			shell_error(Malloc, "str in ft_strjoin");
		while (s1[i] && (str[i] = s1[i]))
			i++;
		while (*s2)
		{
			str[i] = *s2;
			s2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
