/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 21:10:44 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 08:51:16 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>

static void		ft_weiter(t_par *params, t_env **env, char **av)
{
	if (!ft_strcmp(av[0], "clear"))
		write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
	else if (!ft_strcmp(av[0], "manp"))
		pmanp(av, ft_strjoin(params->exec_path, "/manp/"));
	else if (!ft_strcmp(av[0], "help"))
		ft_help(av, ft_strjoin(params->exec_path, "/manp/"));
	else if (!ft_strcmp(av[0], "echo"))
		ft_echo(av);
	else if (!ft_strcmp(av[0], "exit"))
		do_exit(av);
}

void			command_exec(t_par *params, t_env **env, char **av)
{
	if (!ft_strcmp(av[0], "env"))
		exit(42);
	else if (!ft_strcmp(av[0], "setenv"))
		exit(0);
	else if (!ft_strcmp(av[0], "unsetenv"))
		exit(0);
	else if (!ft_strcmp(av[0], "cd"))
		exit(0);
	else if (!ft_strcmp(av[0], "log"))
		plog(params->logs, av);
	else if (!ft_strcmp(av[0], "ft_ls"))
		ft_ls(tab_size(av), av);
	else if (!ft_strcmp(av[0], "ft_grep"))
		ft_grep(av);
	else
		ft_weiter(params, env, av);
}
