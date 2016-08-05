/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 05:25:31 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 05:27:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

t_env				*check_sub(char *line, t_env **env)
{
	t_env			*sub;

	sub = *env;
	while (sub)
	{
		if (!ft_strncmp(sub->env_name, line, ft_strlen(sub->env_name)))
			return (sub);
		sub = sub->next;
	}
	return (NULL);
}
