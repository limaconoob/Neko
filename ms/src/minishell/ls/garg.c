/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 05:00:22 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:03:03 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <unistd.h>
#define STAT struct stat

static int			ft_norm2(t_dir **dir, char *av, int *options)
{
	*dir = idir(av);
	if ((*dir)->nb_files != -1)
		gdir(*dir, options);
	else
		(*dir)->name = ft_strdup(av);
	return (1);
}

static t_dir		**snames(t_dir **dir, t_dir *file, char **av, int *options)
{
	int				cur_dir;
	int				cur_file;
	int				cur_arg;
	struct stat		sb;

	cur_dir = 0;
	cur_file = 0;
	cur_arg = -1;
	while (av[++cur_arg])
	{
		if (lstat(av[cur_arg], &sb) == -1)
			continue ;
		if (ISLNK && stat(av[cur_arg], &sb) == -1)
			lstat(av[cur_arg], &sb);
		if (ISDIR && ft_norm2(&dir[cur_dir], av[cur_arg], options))
			cur_dir++;
		else
			file->files[cur_file++] = ifile(av[cur_arg], sb, options);
	}
	pfiles(file->files, NULL, options);
	ffiles(&(file->files));
	free(file);
	if (cur_file && cur_dir)
		write(1, "\n", 1);
	return (dir);
}

static void			ft_norm1(int *nb_dir, int *nb_files, STAT sb)
{
	if (ISDIR)
		(*nb_dir)++;
	else
		(*nb_files)++;
}

t_dir				**garg(int cur_arg, char **av, int *options)
{
	int				nb_dir;
	t_dir			*files;
	int				nb_files;
	t_dir			**dir;
	struct stat		sb;

	nb_dir = 0;
	nb_files = 0;
	while (av[++cur_arg])
	{
		if (!(*av[cur_arg]))
			ls_error(Fts_open, "fts_open");
		if (lstat(av[cur_arg], &sb) == -1)
			continue ;
		if (ISLNK && stat(av[cur_arg], &sb))
			ft_norm1(&nb_dir, &nb_files, sb);
		else
			ft_norm1(&nb_dir, &nb_files, sb);
	}
	files = idir(NULL);
	files->files = files_malloc(nb_files);
	if (!(dir = (t_dir**)malloc(sizeof(t_dir*) * (nb_dir + 1))))
		ls_error(Malloc, "dir");
	dir[nb_dir] = NULL;
	return (snames(dir, files, av, options));
}
