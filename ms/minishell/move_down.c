/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 23:00:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/15 04:53:50 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				move_down(t_term *term)
{
	int				i;

	i = term->x + term->term_x;
	while (TX < i && TX < T->size)
	{
		if (TY < T->wide && T->curs_y == term->term_y - 1)
			ft_putchar('\n');
		move_it(REC, term);
	}
}
