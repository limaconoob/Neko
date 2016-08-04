/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 10:02:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/30 16:21:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

t_log				*ft_list_reverse2(t_log **get)
{
	t_log			*previous_elem;
	t_log			*tmp;
	t_log			*next_elem;

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
