/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 04:42:02 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:03:14 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>

static t_dir		*ft_read(int nb_files, t_dir *dir, int *options)
{
	struct dirent	*dp;
	struct stat		sb;
	char			*name;

	dir->dirp = opendir(dir->name);
	while ((dp = readdir(dir->dirp)))
	{
		if (options[a] || (dp->d_name)[0] != '.')
		{
			name = ft_strjoin(dir->name, dp->d_name);
			if (lstat(name, &sb) == -1)
			{
				ft_strdel(&name);
				ls_warning(Permission, dp->d_name);
				continue ;
			}
			dir->files[--nb_files] = ifile(dp->d_name, sb, options);
			ft_strdel(&name);
		}
	}
	(void)closedir(dir->dirp);
	return (dir);
}

void				gdir(t_dir *dir, int *options)
{
	struct dirent	*dp;
	struct stat		sb;
	char			*name;

	while ((dp = readdir(dir->dirp)))
	{
		if (options[a] || (dp->d_name)[0] != '.')
		{
			name = ft_strjoin(dir->name, dp->d_name);
			if (lstat(name, &sb) == -1)
			{
				ft_strdel(&name);
				continue ;
			}
			ft_strdel(&name);
			if ((name = dp->d_name) && options[l])
				dir->total += sb.st_blocks;
			dir->nb_files += 1;
			if (options[R] && ISDIR && !ISNOTMAIN)
				dir->nb_sdir += 1;
		}
	}
	(void)closedir(dir->dirp);
	dir->files = files_malloc(dir->nb_files);
	dir->files = ft_dtri(ft_read(dir->nb_files, dir, options), options);
}
