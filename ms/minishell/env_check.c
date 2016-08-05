/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 04:05:10 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 08:43:24 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				env_check(t_par *params, t_env **env, char **av)
{
	if (!ft_strcmp(av[0], "env"))
	{
		if (tab_size(av) == 1)
			penv(env);
		else
			env_exec(params, env, av + 1);
	}
	else if (!ft_strcmp(av[0], "setenv"))
		senv(params, env, av);
	else if (!ft_strcmp(av[0], "unsetenv"))
		uenv(env, av, params);
	else if (!ft_strcmp(av[0], "cd"))
		schdir(env, av);
}
