/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 07:48:40 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 08:01:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static int		kick_first(t_env **env)
{
	t_env		*tmp;

	tmp = (*env)->next;
	ft_strdel(&((*env)->value));
	ft_strdel(&((*env)->env_name));
	free(*env);
	*env = tmp;
	return (1);
}

int				kick_env(t_env **env, char *av)
{
	t_env		*elem;
	t_env		*last;
	t_env		*tmp;

	if (!ft_strcmp((*env)->env_name, av))
		return (kick_first(env));
	last = *env;
	elem = (*env)->next;
	while (elem)
	{
		if (!ft_strcmp(elem->env_name, av))
		{
			tmp = elem->next;
			ft_strdel(&elem->value);
			ft_strdel(&elem->env_name);
			free(elem);
			last->next = tmp;
			elem = tmp;
			return (1);
		}
		elem = elem->next;
		last = last->next;
	}
	return (0);
}
