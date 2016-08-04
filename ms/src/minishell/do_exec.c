/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 21:32:07 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 08:43:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sysexits.h>

static void			error_exec(char *av)
{
	ft_putstr("Fehler: Anweisung nicht gefunden: ");
	ft_putescstr(av);
}

static void			exec_ohne_path(char **av)
{
	if (!ft_strcmp(av[0], "ls"))
		ft_ls(tab_size(av), av);
	else if (!ft_strcmp(av[0], "cat"))
		ft_cat(av);
	else if (!ft_strcmp(av[0], "pwd"))
		ft_putendl(getcwd(NULL, 4096));
	else if (!ft_strcmp(av[0], "grep"))
		ft_grep(av);
	else
		return (error_exec(av[0]));
	exit(EXIT_SUCCESS);
}

static void			check_exec(char **av, char **env)
{
	char			*str;
	struct stat		sb;

	str = last_char(av[0], '/') > -1 ? ft_strrchr(av[0], '/') + 1 : NULL;
	if (str && str + 1)
	{
		str = get_dirpart(av[0]);
		if (access(str, X_OK))
		{
			ft_strdel(&str);
			shell_error(Access, str);
		}
		ft_strdel(&str);
		ft_signal(-1);
		execve(av[0], av, env);
		if (lstat(av[0], &sb) == -1)
			shell_error(MissingFile, av[0]);
	}
}

void				do_exec(char **env, char **av, t_par *params)
{
	char			*str;
	t_path			*path;

	if (iscom(av[0]))
		return (command_exec(params, params->env, av));
	check_exec(av, env);
	path = *(params->path);
	while (path)
	{
		if (access(PTH, X_OK))
		{
			path = path->next;
			continue ;
		}
		str = ft_strjoin(path->path_name, "/");
		str = ft_concat(str, av[0], ft_strlen(av[0]));
		execve(str, av, env);
		ft_strdel(&str);
		path = path->next;
	}
	exec_ohne_path(av);
	exit(EX_USAGE);
}
