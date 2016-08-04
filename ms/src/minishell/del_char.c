/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 05:10:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 21:12:12 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				del_char(t_term *term)
{
	char			*tmp1;
	char			*tmp2;

	if (!term->x)
		return ;
	move_it(LIN, term);
	ft_putstr(&(term->line[term->x + 1]));
	ft_putchar(' ');
	tmp1 = ft_strdup(&(term->line[term->x + 1]));
	tmp2 = ft_strsub(term->line, 0, term->x);
	ft_strdel(&(term->line));
	if (tmp2)
		term->line = ft_concat(tmp2, tmp1, ft_strlen(tmp1));
	else
		term->line = ft_strdup(tmp1);
	free(tmp1);
	term->size--;
	if ((term->size + term->begin_x) % term->term_x == term->term_x - 1)
		term->wide--;
	move_it(0, term);
	if (!(term->size))
		return (ft_strdel(&term->line));
}
