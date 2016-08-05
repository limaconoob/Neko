/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:43:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 04:59:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <sys/ioctl.h>

void				get_size(int x, int y, t_par *params)
{
	static int		sx;
	static int		sy;
	static t_par	*stock;

	if (x == -1 && y == -1)
	{
		if (params->term->caps && term_coord() - 1)
			params->term->curs_y = term_coord() - 1;
		params->term->term_y = sy;
		params->term->term_x = sx;
		stock = params;
	}
	else
	{
		sx = x;
		sy = y;
	}
}
