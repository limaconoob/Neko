/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 05:25:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/21 08:04:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

t_env				*check_nsub(char *line, t_env **env)
{
	t_env			*sub;

	sub = *env;
	while (sub)
	{
		if (!ft_strcmp(sub->env_name, line))
			return (sub);
		sub = sub->next;
	}
	return (NULL);
}
