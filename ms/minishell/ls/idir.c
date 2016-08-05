/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 10:07:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:56:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_dir			*idir(char *name)
{
	t_dir		*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		ls_error(Malloc, "dir in idir");
	if (name)
	{
		dir->dirp = opendir(name);
		if (dir->dirp == NULL)
		{
			dir->nb_files = -1;
			return (dir);
		}
		dir->name = ft_strjoin(name, "/");
		if (!dir->name)
			ls_error(Malloc, "dir->name in idir");
	}
	dir->total = 0;
	dir->nb_sdir = 0;
	dir->nb_files = 0;
	return (dir);
}
