/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uenv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:17:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/15 09:32:45 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			uenv_err(char *av)
{
	ft_putstr("Fehler (unsetenv): ");
	ft_putstr(av);
	ft_putendl(": Kein Environmentvariable");
}

void				uenv(t_env **env, char **av, t_par *params)
{
	int				i;
	int				k;

	i = 0;
	if (tab_size(av) == 1)
	{
		ft_putstr("Fehler (unsetenv): Benutzung: ");
		return (ft_putendl("unsetenv [env_name ...]"));
	}
	if (!env || !(*env))
	{
		ft_putendl("Es gibt kein Environment, dann du nicht mehr ");
		return (ft_putendl("  Environmentvariable zerstören kannst."));
	}
	while (av[++i])
	{
		if (kick_env(env, av[i]))
		{
			if (!ft_strcmp(av[i], "PATH"))
				set_path(params, NULL);
			continue ;
		}
		uenv_err(av[i]);
	}
}
