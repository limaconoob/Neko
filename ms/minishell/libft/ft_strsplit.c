/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:15:46 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 04:16:48 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int tek;

	tek = 0;
	while (*s && *s == c)
		s++;
	if (*s != '\0')
		tek++;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			tek++;
		s++;
	}
	return (tek);
}

char		**ft_strsplit(char const *s, char c)
{
	int		tek;
	char	*str;
	char	**tab;

	if (s == NULL || !c)
		return (NULL);
	str = (char*)s;
	tek = count(str, c);
	tab = (char **)malloc(sizeof(char*) * (tek + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			if (str != s)
				*(tab++) = ft_strsub(str, 0, s - str);
			str = (char*)s + 1;
		}
		s++;
	}
	if (str != s)
		*(tab++) = ft_strsub(str, 0, s - str);
	*tab = NULL;
	return (tab - tek);
}
