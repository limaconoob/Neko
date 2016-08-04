/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 07:29:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 06:15:39 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			insert(t_term *term, char push)
{
	char			*tmp1;
	char			*tmp2;

	ft_putstr(&(term->line[term->x]));
	tmp1 = ft_strdup(&(term->line[term->x]));
	if (term->x > 0)
	{
		tmp2 = ft_strsub(term->line, 0, term->x);
		tmp2 = ft_concat(tmp2, &push, 1);
	}
	else
		tmp2 = ft_strsub(&push, 0, 1);
	ft_strdel(&(term->line));
	term->line = ft_concat(tmp2, tmp1, ft_strlen(tmp1));
	ft_strdel(&tmp1);
}

void				ins_char(t_term *term, char push)
{
	char			*tmp1;
	char			*tmp2;

	if (push && push != '\n')
		ft_putchar(push);
	if (term->size && term->x == term->size)
		term->line = ft_concat(term->line, &push, 1);
	else
		insert(term, push);
	term->size++;
	if (T->size + TBX >= T->term_x && (T->size + TBX) % term->term_x == 0)
	{
		term->wide++;
		if (T->curs_y + (T->wide - T->y) == T->term_y)
			term->curs_y--;
		ft_putchar('\n');
	}
	move_it(REC, term);
}
