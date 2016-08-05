/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:23:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 07:56:54 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static char		*parse_value(char **value)
{
	int			i;

	if (!(*value)[0])
		return (ft_strdup("2"));
	i = 0;
	while ((*value)[i] && (*value)[i] >= '0' && (*value)[i] <= '9')
		i++;
	if ((*value)[i] && ((*value)[i] < '0' || (*value)[i] > '9'))
		return (ft_strdup("1"));
	return (ft_itoa(ft_atoi(*value) + 1));
}

void			set_shlvl(t_env **env)
{
	t_env		*elem;
	char		*tmp;

	if (*env)
	{
		elem = *env;
		while (elem)
		{
			if (!ft_strcmp(elem->env_name, "SHLVL"))
			{
				tmp = elem->value;
				elem->value = parse_value(&(elem->value));
				return (ft_strdel(&tmp));
			}
			elem = elem->next;
		}
	}
}
