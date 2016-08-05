/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:22:21 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 04:25:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static char		*norm(char *s1, int pot)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(ft_strlen(s1) - pot)))
		shell_error(Malloc, "str in ft_concat2");
	while (s1[i + pot + 1] && (str[i] = s1[i + pot + 1]))
		i++;
	str[i] = '\0';
	return (str);
}

char			*ft_concat(char *s1, char *s2, int pot)
{
	int			i;
	int			k;
	char		*str;

	str = NULL;
	i = 0;
	k = 0;
	if (!s1 && s2)
		return (ft_strsub(s2, 0, pot));
	if (!s2 && s1[pot])
		str = norm(s1, pot);
	else if (s2)
	{
		if (!(str = (char*)malloc(ft_strlen(s1) + pot + 1)))
			shell_error(Malloc, "str in ft_concat2");
		while (s1[i] && (str[i] = s1[i]))
			i++;
		while (s2[k] && (str[k + i] = s2[k]) && k < pot)
			k++;
		str[i + k] = '\0';
	}
	ft_strdel(&s1);
	return (str);
}
