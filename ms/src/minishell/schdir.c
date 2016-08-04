/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 05:18:02 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/23 20:11:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>
#include <sys/stat.h>

static void			cenv(t_env **env, char *str, char *stock)
{
	t_env			*elem;
	char			*tmp;

	elem = *env;
	while (elem)
	{
		if (!ft_strcmp(str, elem->env_name))
		{
			ft_strdel(&(elem->value));
			elem->value = stock;
			return ;
		}
		elem = elem->next;
	}
	tmp = ft_strjoin(str, "=");
	push_env(env, ft_concat(tmp, stock, ft_strlen(stock)));
}

static void			cd_error(char *av)
{
	struct stat		sb;

	ft_putstr("Fehler (cd): ");
	ft_putstr(av);
	if (lstat(av, &sb) == -1)
		ft_putendl(": Kein Datei oder Ordner");
	else if (ISDIR)
		ft_putendl(": Zugang ist verboten");
	else
		ft_putendl(": Nicht ein Ordner");
}

static void			opt_cd(t_env **env, char *str)
{
	t_env			*path;
	char			*tmp;

	path = *env;
	while (path && ft_strcmp(path->env_name, str))
		path = path->next;
	if (path && !ft_strcmp(path->env_name, str))
	{
		tmp = getcwd(NULL, 4096);
		if (chdir(path->value) != -1)
			cenv(env, "OLDPWD", tmp);
		else
			cd_error(path->value);
		cenv(env, "PWD", getcwd(NULL, 4096));
	}
	else
	{
		ft_putstr("Fehler (cd): Variable ");
		ft_putstr(str);
		ft_putendl(" ist nicht verfügbar");
	}
}

void				schdir(t_env **env, char **av)
{
	if (tab_size(av) > 2)
		ft_putendl("Fehler (cd): So viele Argumente");
	else if (!ft_strcmp(av[1], "~"))
		opt_cd(env, "HOME");
	else if (!ft_strcmp(av[1], "-"))
		opt_cd(env, "OLDPWD");
	else
	{
		cenv(env, "OLDPWD", getcwd(NULL, 4096));
		if (chdir(av[1]) != -1)
			cenv(env, "PWD", getcwd(NULL, 4096));
		else
			cd_error(av[1]);
	}
}
