/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 11:22:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 11:26:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				move_to(t_term *term, int get)
{
	int				i;

	if (!get)
		return ;
	i = 0;
	if (get > 0)
		while (i++ < get && TX < term->size)
			move_it(REC, term);
	else
		while (i-- > get && TX > 0)
			move_it(LIN, term);
}
