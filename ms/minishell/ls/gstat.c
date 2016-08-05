/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:58:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:56:04 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>
#include <time.h>

static char			*gusr(uid_t uid)
{
	struct passwd	*pwd;
	char			*str;

	pwd = getpwuid(uid);
	if (pwd == NULL)
		return (ft_strdup("jpepin  "));
	str = ft_strdup(pwd->pw_name);
	if (ft_strlen(pwd->pw_name) < 8)
		str = ft_concat(str, "        ", 8 - ft_strlen(pwd->pw_name));
	else
		str = ft_concat(str, " ", 1);
	return (str);
}

static char			*ggrp(gid_t gid, int size)
{
	struct group	*grp;
	char			*str;
	char			*tmp;
	char			*sp;

	grp = getgrgid(gid);
	if (grp == NULL)
		return (ft_strdup("2015_paris            "));
	tmp = grp->gr_name;
	sp = "           ";
	if (ft_strlen(tmp) < 11)
		str = ft_concat(ft_strdup(tmp), sp, 10 - ft_strlen(tmp));
	else
		str = ft_strjoin(tmp, " ");
	sp = "        ";
	if (jy_intlen(size) < 7)
		str = ft_concat(str, sp, 8 - jy_intlen(size));
	else
		str = ft_strjoin(tmp, " ");
	return (str);
}

static char			*gmnmj(int rdev, gid_t gid, char **file)
{
	int				minor;
	int				major;
	char			*name;
	char			*tmp;

	major = (rdev >> 24) & 0xFF;
	minor = rdev & 0xFF;
	file[4] = ggrp(gid, major);
	name = ft_itoa(major);
	name = ft_concat(name, ",    ", 5 - jy_intlen(minor));
	tmp = ft_itoa(minor);
	name = ft_concat(name, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
	return (name);
}

static char			*glink(char *name)
{
	char			*link_name;
	char			*tmp1;
	char			*tmp2;
	int				ret;

	if (!(tmp2 = (char*)malloc(201)))
		ls_error(Malloc, NULL);
	ret = readlink(name, tmp2, 200);
	tmp2[ret] = '\0';
	if (ft_strchr(name, '/'))
		name = ft_strchr(name, '/') + 1;
	if (!(tmp1 = ft_strjoin(name, " -> ")))
		ls_error(Malloc, NULL);
	link_name = ft_strjoin(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (link_name);
}

void				gstat(char **file, char *dir_name)
{
	struct stat		sb;
	char			*str;

	str = ft_strjoin(dir_name, *file);
	lstat(str, &sb);
	ft_strdel(&str);
	file[1] = gtype(sb);
	str = ft_itoa(sb.st_nlink);
	file[2] = ft_strjoin(str, " ");
	ft_strdel(&str);
	if ((file[3] = gusr(sb.st_uid)) && ISCHR)
		file[5] = gmnmj(sb.st_rdev, sb.st_gid, file);
	else
	{
		file[4] = ggrp(sb.st_gid, sb.st_size);
		file[5] = ft_itoa(sb.st_size);
	}
	file[6] = gtime(sb.st_mtime);
	if (ISLNK)
	{
		str = ft_strjoin(dir_name, *file);
		file[7] = glink(str);
		*file = NULL;
		ft_strdel(&str);
	}
}
