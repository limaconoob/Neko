/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   senv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:17:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 09:21:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			error_setenv(char *av, int flag)
{
	ft_putstr("Fehler (setenv): ");
	ft_putendl(av);
	if (!flag)
		ft_putendl("Benutzung: setenv [env_name]=[value]");
	else if (flag == -1)
		ft_putendl("Die Argumente von setenv muß kein '?' oder '$' enthalten");
}

static int			swap_env(t_env **env, char *av, int k)
{
	t_env			*new_env;
	int				push;

	push = 1;
	new_env = *env;
	while (new_env)
	{
		if (!ft_strncmp(new_env->env_name, av, k))
		{
			ft_strdel(&(new_env->value));
			new_env->value = ft_strdup(&(av[k + 1]));
			push = 0;
		}
		new_env = new_env->next;
	}
	return (push);
}

void				senv(t_par *params, t_env **env, char **av)
{
	int				i;
	int				k;

	i = 0;
	if (tab_size(av) == 1)
		ft_putendl("Fehler (setenv): Benutzung: setenv [env_name]=[value]");
	while (av[++i])
	{
		k = env_parse(av[i]);
		if (k)
		{
			if (!ft_strncmp(av[i], "PATH", k))
				set_path(params, &av[i][k + 1]);
			if (swap_env(env, av[i], k))
				push_env(env, av[i]);
		}
		else
			return (error_setenv(av[i], k));
	}
}
