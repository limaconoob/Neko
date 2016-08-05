/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncommands.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:02:05 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/19 21:15:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

t_ncom			*ncommands(t_ncom **ncom, char **multi)
{
	t_ncom		*stock;
	int			cur_com;

	stock = NULL;
	if (!multi || !*multi)
		return (*ncom);
	cur_com = -1;
	while (multi[++cur_com])
	{
		if (*ncom)
		{
			stock->next = incom(multi[cur_com]);
			stock = stock->next;
		}
		else
		{
			stock = incom(multi[cur_com]);
			*ncom = stock;
		}
	}
	free(multi);
	return (*ncom);
}
