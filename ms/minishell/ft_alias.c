/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 13:24:13 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/16 13:54:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void			ft_alias(char **av, t_alias **aliases)
{
	int			i;
	t_alias		*new_elem;

	i = 0;
	while (av[++i])
	{
		if (!aliases && !((aliases = (t_alias**)malloc(sizeof(t_alias*)))))
			return (NULL);
		if (!*aliases)
			*aliases = ialias(av[i]);
		else if (*aliases && !new_elem)
		{
			new_elem = ialias(av[i]);
			(*aliases)->next = new_elem;
		}
		else if (new_elem)
		{
			new_elem->next = ialias(av[i]);
			new_elem = new_elem->next;
		}
	}
}
