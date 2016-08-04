/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 01:54:42 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:55:44 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>

static int			ft_free(t_dir **optr, char **tek)
{
	ft_strdel(&((*optr)->name));
	ffiles(&((*optr)->files));
	free(*optr);
	ft_strdel(tek);
	return (1);
}

static void			fd_warning(char *tek)
{
	write(1, "\n", 1);
	put_name(tek);
	ls_warning(Fd, tek);
}

static t_dir		*put_tek(char **tek)
{
	t_dir			*optr;

	write(1, "\n", 1);
	put_name(*tek);
	*tek = ft_concat(*tek, "/", 1);
	optr = idir(*tek);
	return (optr);
}

static void			ft_norm(char **tek, int *options)
{
	t_dir			*optr;

	optr = put_tek(tek);
	if (optr->nb_files != -1)
	{
		gdir(optr, options);
		if (options[l] && optr->nb_files)
			ptotal(optr->total);
		pfiles(optr->files, *tek, options);
		goptr(*tek, optr, options);
		ffiles(&(optr->files));
		ft_strdel(&(optr->name));
	}
	else
		pperm(*tek);
	free(optr);
}

void				goptr(char *get, t_dir *dir, int *options)
{
	int				k;
	struct stat		sb;
	char			*name;
	char			*tek;

	k = -1;
	while (++k < dir->nb_files)
	{
		name = *(dir->files[k]);
		tek = ft_strjoin(get, name);
		if (name && !ft_strcmp(name, "3") && !opendir(tek))
			fd_warning(tek);
		else if (name && lstat(tek, &sb) != -1 && !ISNOTMAIN && ISDIR)
			ft_norm(&tek, options);
		ft_strdel(&tek);
	}
}
