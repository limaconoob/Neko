/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_newprompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:40:41 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 08:26:22 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				put_newprompt(t_par *params, int flag)
{
	static t_par	*get;

	if (flag == -1)
	{
		params = get;
		move_to(TERM, TERM->size - TERM->x);
		ft_putchar('\n');
	}
	if (params->term->line)
		ft_strdel(&(params->term->line));
	if (params->term->cutter)
		ft_strdel(&(params->term->cutter));
	params->term->x = 0;
	params->term->wide = 0;
	params->term->size = 0;
	params->term->y = 0;
	if (params->term->caps)
		put_prompt("jpepin $> ", params);
	get = params;
}
