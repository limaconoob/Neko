/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:55:37 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/09 07:36:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void			push_env(t_env **env, char *line)
{
	t_env		*new_env;
	t_env		*enver;

	enver = *env;
	if (!enver)
		new_env = ienv(line);
	else
	{
		new_env = ienv(line);
		new_env->next = enver;
	}
	*env = new_env;
}
