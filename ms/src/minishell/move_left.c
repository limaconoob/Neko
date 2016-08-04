/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 22:26:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 10:48:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			get_back(t_term *term)
{
	char			*tmp;
	char			*tmp2;

	if (TY)
	{
		tmp = ft_strsub(TL, TX - T->term_x, T->term_y * T->term_x);
		ft_putstr(tmp);
	}
	else
	{
		tmp = ft_strsub(TL, 0, T->term_x - TBX);
		tmp2 = ft_strsub(TL, T->term_x - TBX + 1, (T->term_y - 1) * T->term_x);
		tmp = ft_concat(tmp, tmp2, ft_strlen(tmp2));
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(T->prompt, tmp);
		ft_putstr(tmp);
	}
	free(tmp);
}

static void			back_chariot(t_term *term)
{
	char			*tmp;
	char			*tmp2;

	term->y--;
	if (term->curs_y > 0)
		term->curs_y--;
	else
	{
		term->curs_x = term->y ? 0 : term->begin_x;
		get_back(term);
		move_it(0, term);
	}
	term->x--;
	term->curs_x = term->term_x - 1;
}

void				move_left(t_term *term)
{
	int				moins;

	moins = 1;
	if (term->curs_x > 0 && TX > 0)
	{
		if (TL[TX - 1] == '\t')
			moins = 4;
		TX--;
		T->curs_x -= moins;
	}
	else if (!T->curs_x)
		back_chariot(T);
}
