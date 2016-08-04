/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 10:02:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/13 11:14:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

t_env				*ft_list_reverse(t_env **get)
{
	t_env			*previous_elem;
	t_env			*next_elem;
	t_env			*tmp;

	next_elem = *get;
	tmp = *get;
	previous_elem = NULL;
	while (tmp->next)
	{
		tmp = next_elem->next;
		next_elem->next = previous_elem;
		previous_elem = next_elem;
		if (tmp->next)
			next_elem = tmp;
		else
		{
			tmp->next = next_elem;
			next_elem = tmp;
			break ;
		}
	}
	return (next_elem);
}
