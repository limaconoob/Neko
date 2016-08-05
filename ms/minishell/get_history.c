/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:08:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 08:06:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			put_newline(t_term *term, t_log *log)
{
	move_to(term, term->size - TX);
	del_size(term, T->size);
	put_termstr(term, log->line);
}

static void			move_hist(t_log **log, t_term *term, int way)
{
	if ((*log)->line)
		ft_strdel(&((*log)->line));
	(*log)->line = ft_strdup(term->line);
	if (way == TOP)
		(*log) = (*log)->next;
	else if (way == UNT)
		(*log) = (*log)->last;
	put_newline(term, (*log));
}

void				get_history(t_log **glogs, t_term *term, int way)
{
	static t_log	*log = NULL;
	char			*str;

	if (!log && (!glogs || (glogs && !(*glogs))))
		return ;
	if (way == -1)
		log = *glogs;
	str = NULL;
	if (way == TOP || way == UNT)
		move_hist(&log, term, way);
}
