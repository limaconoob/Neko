/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 23:00:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/13 06:51:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				move_up(t_term *term)
{
	if ((term->curs_y - 1) && TY > 0)
	{
		if (TY - 1 || term->curs_x >= TBX)
			term->x -= term->term_x;
		term->curs_y--;
	}
	if (!TY || (!(TY - 1) && term->curs_x < TBX))
	{
		TX = 0;
		term->curs_x = term->begin_x;
	}
	if (TY)
		term->y--;
}
