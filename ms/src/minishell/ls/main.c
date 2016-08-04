/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 02:02:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 07:13:55 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <unistd.h>

static void			put_arg(t_dir *dir, int *options)
{
	if (options[l] && dir->nb_files)
		ptotal(dir->total);
	if (ft_strcmp(dir->name, "/"))
		dir->name[ft_strlen(dir->name)] = '/';
	pfiles(dir->files, dir->name, options);
	if (options[R])
		goptr(dir->name, dir, options);
	ft_strdel(&dir->name);
	ffiles(&(dir->files));
	free(dir);
}

static t_dir		**handle_args(int ac, char **args, int *options)
{
	t_dir			**dirs;
	int				cur_dir;

	ft_tri(args, ac, options);
	dirs = garg(-1, args, options);
	cur_dir = -1;
	while (dirs[++cur_dir])
	{
		if (dirs[cur_dir]->nb_files != -1)
			dirs[cur_dir]->name[ft_strlen(dirs[cur_dir]->name) - 1] = '\0';
		if (ac > 1)
			put_name(dirs[cur_dir]->name);
		if (dirs[cur_dir]->nb_files == -1)
			ls_warning(Permission, dirs[cur_dir]->name);
		else
			put_arg(dirs[cur_dir], options);
		if (dirs[cur_dir + 1])
			write(1, "\n", 1);
	}
	return (dirs);
}

void				ft_ls(int argc, char **argv)
{
	int				options[6];
	int				cur_arg;
	t_dir			**dirs;

	cur_arg = soptions(argc, argv, options);
	if (cur_arg == -1)
		return ;
	if (cur_arg == argc)
	{
		if (!(dirs = (t_dir**)malloc(sizeof(t_dir*))))
			ls_error(Malloc, "dirs");
		*dirs = idir(".");
		gdir(*dirs, options);
		if (options[l] && (*dirs)->nb_files)
			ptotal((*dirs)->total);
		pfiles((*dirs)->files, (*dirs)->name, options);
		if (options[R])
			goptr("./", *dirs, options);
		ffiles(&((*dirs)->files));
		free((*dirs)->name);
		free(*dirs);
	}
	else
		dirs = handle_args(argc - cur_arg, &argv[cur_arg], options);
	free(dirs);
}
