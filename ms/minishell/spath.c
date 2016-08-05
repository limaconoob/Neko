/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:11:22 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 01:26:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static void		mpath(char **tab, t_path **path)
{
	int			i;
	t_path		*stock;

	i = -1;
	stock = NULL;
	while (tab[++i])
	{
		if (stock)
		{
			stock->next = ipath(tab[i]);
			stock = stock->next;
		}
		else
		{
			stock = ipath(tab[i]);
			*path = stock;
		}
	}
}

void			spath(t_path **paths, char *value)
{
	char		*tmp;
	char		**tab;

	if (!value)
		return ;
	tmp = ft_strtrim(value);
	tab = ft_strsplit(tmp, ':');
	mpath(tab, paths);
	ft_strdel(&tmp);
	free(tab);
}
