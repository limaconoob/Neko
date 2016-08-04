/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpath.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:01:00 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/13 11:13:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

t_path			**rpath(t_par *params)
{
	char		*tmp;
	char		**tab;
	t_env		*env;

	if (*(params->env))
	{
		env = *(params->env);
		while (env->next && ft_strcmp(env->env_name, "PATH"))
			env = env->next;
		if (!ft_strcmp(env->env_name, "PATH"))
			spath(params->path, env->value);
		else
			*(params->path) = NULL;
	}
	else
		*(params->path) = NULL;
	return (params->path);
}
