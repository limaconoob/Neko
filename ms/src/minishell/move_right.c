/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 22:08:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 10:49:00 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			retour_chariot(t_term *term)
{
	char			*tmp;

	term->curs_x = 0;
	term->x++;
	term->y++;
	if (term->curs_y < term->term_y - 1)
		term->curs_y++;
	else
	{
		tmp = ft_strsub(term->line, term->x, term->x + term->term_x - 1);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
}

void				move_right(t_term *term)
{
	int				plus;

	plus = 1;
	if (T->curs_x < T->term_x - 1 && TX < T->size)
	{
		if (TL[TX] == '\t')
			plus = 4;
		TX++;
		T->curs_x += plus;
	}
	else if (T->curs_x == T->term_x - 1 && TX < T->size)
		retour_chariot(T);
}
