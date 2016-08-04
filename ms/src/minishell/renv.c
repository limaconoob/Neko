/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:48:13 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 01:28:38 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static void		create_env(t_env **stock, char *envp)
{
	(*stock)->next = ienv(envp);
	(*stock) = (*stock)->next;
	if (!ft_strcmp((*stock)->env_name, "_"))
	{
		ft_strdel(&((*stock)->value));
		(*stock)->value = ft_concat(getcwd(NULL, 4096), "/minishell", 10);
	}
}

t_env			**renv(t_env **env, char **envp)
{
	t_env		*stock;
	int			i;

	stock = NULL;
	*env = NULL;
	if (!envp || !(*envp))
		return (env);
	i = -1;
	while (envp[++i])
	{
		if (*env)
			create_env(&stock, envp[i]);
		else
		{
			stock = ienv(envp[i]);
			*env = stock;
		}
	}
	*env = ft_list_reverse(env);
	return (env);
}
