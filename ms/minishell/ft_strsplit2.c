/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:17:18 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/21 21:42:37 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static int		ft_count(char *str, char c)
{
	int			count;
	int			quote;

	count = 0;
	quote = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			while (*str && (*str != c || quote))
			{
				if (*str == '\"')
					quote ^= 1;
				str++;
			}
			count++;
		}
	}
	return (count);
}

static void		get_ttab(char **tab, char *str, char c)
{
	int			count;
	int			i;
	int			quote;

	count = 0;
	quote = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			i = 0;
			while (str[i] && (str[i] != c || quote))
			{
				if (str[i] == '\"')
					quote ^= 1;
				i++;
			}
			tab[count++] = ft_strsub(str, 0, i);
			str += i;
		}
	}
	tab[count] = NULL;
}

char			**ft_strsplit2(char *str, char c)
{
	char		**tab;

	if (!str)
		return (NULL);
	if (!((tab = (char**)malloc(sizeof(char*) * (ft_count(str, c) + 1)))))
		shell_error(Malloc, "tab in ft_strsplit2");
	get_ttab(tab, str, c);
	return (tab);
}
