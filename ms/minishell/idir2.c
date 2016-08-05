/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idir2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 10:07:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 09:38:51 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

t_dir			*idir2(char *name)
{
	t_dir		*dir;

	if (!(dir = (t_dir*)malloc(sizeof(t_dir))))
		shell_error(Malloc, "dir in idir2");
	dir->dirp = opendir(name);
	dir->name = name;
	if (dir->dirp == NULL)
	{
		dir->nb_files = -1;
		return (dir);
	}
	dir->total = 0;
	dir->nb_sdir = 0;
	dir->nb_files = 0;
	return (dir);
}
