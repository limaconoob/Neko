/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:30:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/20 22:45:26 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>

void				reset_cd(t_env **env)
{
	t_env			*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp("HOME", tmp->env_name))
		{
			if (chdir(tmp->value) == -1)
				chdir("/");
			return ;
		}
		tmp = tmp->next;
	}
	chdir("/");
}
