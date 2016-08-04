/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:15:46 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/21 21:48:44 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static int			ft_count(char *str)
{
	int				count;
	int				quote;

	count = 0;
	quote = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str)
		{
			while (*str && (!ft_isspace(*str) || quote))
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

static void			get_ttab(char **tab, char *str)
{
	int				count;
	int				i;
	int				quote;

	count = 0;
	quote = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str)
		{
			i = 0;
			while (str[i] && (!ft_isspace(str[i]) || quote))
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

char				**ft_splitspaces(char *str)
{
	char			**tab;

	if (!str)
		return (NULL);
	if (!((tab = (char**)malloc(sizeof(char*) * (ft_count(str) + 1)))))
		shell_error(Malloc, "tab in ft_splitspaces");
	get_ttab(tab, str);
	return (tab);
}
