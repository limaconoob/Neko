/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbrack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:28:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 06:11:42 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				clean_fl(t_par *params)
{
	KFL->akkolade = 0;
	KFL->klammern = 0;
	KFL->zitate = 0;
	KFL->zitat = 0;
	KFL->lzitat = 0;
	KFL->haken = 0;
}

static int			clear_flags(t_par *params)
{
	if (TERM->line)
		ft_strdel(&TERM->line);
	if (TERM->cutter)
		ft_strdel(&TERM->cutter);
	clean_fl(params);
	put_newprompt(params, 0);
	return (-1);
}

static int			error_brack(t_par *params)
{
	if (KFL->klammern < 0)
		shell_warning(ExtraFlag, "()");
	else if (KFL->haken < 0)
		shell_warning(ExtraFlag, "[]");
	else if (KFL->akkolade < 0)
		shell_warning(ExtraFlag, "{}");
	if (KFL->klammern < 0 || KFL->haken < 0 || KFL->akkolade < 0)
		return (clear_flags(params));
	return (0);
}

static int			set_getbrack(t_par *params)
{
	if (ALL_FLAGS > 0)
		ft_putchar('\n');
	if (!TERM->caps)
		return (ALL_FLAGS);
	if (KFL->zitate == 1 && !KFL->zitat && !KFL->lzitat)
		put_prompt("Zitate \"> ", params);
	else if (KFL->zitat == 1 && !KFL->zitate && !KFL->lzitat)
		put_prompt("Zitat '> ", params);
	else if (KFL->lzitat == 1 && !KFL->zitat && !KFL->zitate)
		put_prompt("Lzitat `> ", params);
	else if (KFL->akkolade > 0)
		put_prompt("Akkolade }> ", params);
	else if (KFL->klammern > 0)
		put_prompt("Klammern )> ", params);
	else if (KFL->haken > 0)
		put_prompt("Haken ]> ", params);
	return (ALL_FLAGS);
}

int					ft_getbrack(t_par *params)
{
	int				i;

	i = -1;
	clean_fl(params);
	while (TERM->cutter[++i])
	{
		ft_isbrack(TERM->cutter[i], TERM);
		if (error_brack(params) == -1)
			return (-1);
	}
	return (set_getbrack(params));
}
