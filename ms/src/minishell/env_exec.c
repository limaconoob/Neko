/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:33:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 09:21:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static void		get_new(t_par *params, t_env **new_env, char *av, int k)
{
	t_env		*tmp;
	int			push;

	if (!ft_strncmp(av, "PATH", k))
		set_path(params, &av[k + 1]);
	tmp = *new_env;
	push = 1;
	while (tmp)
	{
		if (ft_strlen(tmp->env_name) == k && !ft_strncmp(tmp->env_name, av, k))
		{
			ft_strdel(&(tmp->value));
			tmp->value = ft_strdup(&(av[k + 1]));
			push = 0;
		}
		tmp = tmp->next;
	}
	if (push)
		push_env(new_env, av);
}

static void		env_error(char *av, int flag)
{
	ft_putstr("Fehler (env): ");
	ft_putendl(av);
	if (!flag)
		ft_putendl("Benutzung: env ([env_name]=[value])");
	else if (flag == -1)
		ft_putendl("Die Argumente von env muß kein '?' oder '$' enthalten");
}

void			env_exec(t_par *params, t_env **env, char **av)
{
	t_env		**new_env;
	int			k;
	int			i;

	if (!((new_env = (t_env**)malloc(sizeof(t_env*)))))
		shell_error(Malloc, "new_env in env_exec");
	new_env = renv(new_env, tabenv(env));
	i = -1;
	while (av[++i])
	{
		k = env_parse(av[i]);
		if (k > 0)
			get_new(params, new_env, av[i], k);
		else
			return (env_error(av[i], k));
	}
	penv(new_env);
}
