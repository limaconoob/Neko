/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_afterline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 07:36:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/15 07:42:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				clear_afterline(t_term *term)
{
	int				i;
	char			*tmp;

	i = term->x;
	while (T->curs_x < term->term_x - 1)
		move_it(REC, term);
	while (TX > i + 1)
		del_char(term);
}
