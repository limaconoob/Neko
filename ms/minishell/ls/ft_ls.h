/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 03:06:47 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 20:01:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <dirent.h>

# define ISDIR (!(((sb.st_mode | 4095) - 4095) - S_IFDIR))
# define ISLNK (!(((sb.st_mode | 4095) - 4095) - S_IFLNK))
# define ISCHR (!(((sb.st_mode | 4095) - 4095) - S_IFCHR))
# define ISUID (sb.st_mode & S_ISUID)
# define ISGID (sb.st_mode & S_ISGID)
# define ISVTX (sb.st_mode & S_ISVTX)
# define ISNOTMAIN (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))

void				ft_ls(int argc, char **argv);

/*
**	----------------------------------------------------------------------------
**	t_options wird verwendet, Optionen zu fangen.
**	t_error wird verwendet, Fehler zu fangen und das Program verlassen.
**	t_warning wird verwendet, Fehler zu warnen (das Program ist behalten).
**	(Beobachten Sie die Fehlereinstellungen)
*/

typedef enum		e_options
{
	R,
	a = 2,
	l,
	r,
	t
}					t_options;

typedef enum		e_error
{
	Usage,
	Usagelong,
	Malloc,
	Opendir,
	Stat,
	Fts_open
}					t_error;

typedef enum		e_warning
{
	Missingfile,
	Permission,
	Fd
}					t_warning;

/*
**	----------------------------------------------------------------------------
**	t_dir wird verwendet, Ordner zu schaffen.
*/

typedef struct		s_dir
{
	char			*name;
	char			***files;
	int				total;
	int				nb_files;
	int				nb_sdir;
	DIR				*dirp;
}					t_dir;

/*
**	----------------------------------------------------------------------------
**	Die Funktionen, dass die Optionen und Fehler einstellen.
**	(error == [project]_*.c | set == s*.c)
*/

void				ls_error(int type, char *prob);
void				ls_warning(int type, char *prob);
int					soptions(int ac, char **av, int *options);

/*
**	----------------------------------------------------------------------------
**	Die Funktionen, dass etwas inizialisiert. (init == i*.c)
*/

t_dir				*idir(char *name);
char				**ifile(char *arg, struct stat sb, int *options);
char				***files_malloc(int size);
void				ffiles(char ****files);

/*
**	----------------------------------------------------------------------------
**	Die Funktionen, dass etwas sucht um zu fangen. (get == g*.c)
*/

void				gdir(t_dir *dir, int *options);
char				*gtime(time_t tek);
char				*gtype(struct stat sb);
void				gstat(char **file, char *dir_name);
t_dir				**garg(int cur_arg, char **av, int *options);
void				goptr(char *get, t_dir *dir, int *options);

/*
**	----------------------------------------------------------------------------
**	Zeigen Funktionen. (put == p*.c)
*/

void				put_name(char *put);
void				pfiles(char ***files, char *name, int *options);
void				pmiss(char **av);
void				pperm(char *tek);
void				ptotal(int total);

/*
**	----------------------------------------------------------------------------
**	Die Funktionen, die wertlos sind. (libft == ft_*.c)
*/

char				*ft_concat(char *s1, char *s2, int pot);
char				***ft_dtri(t_dir *dir, int *options);
void				ft_tri(char **file_names, int i, int *options);
int					ft_swap_str(char ***av, int i);
int					ft_swap_str2(char **av, int i);
void				ft_sort_time(int ac, char ***av, time_t *time, char *name);
void				ft_sort_time2(int ac, char **av, time_t *time);

/*
**	----------------------------------------------------------------------------
*/

#endif
