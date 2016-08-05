/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 22:26:48 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 22:31:36 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			ft_norm1(t_term *term, t_par *params)
{
	while (TL[term->x - 2] != '$' && TL[term->x - 1] != '?')
		move_it(REC, term);
	del_size(term, 2);
	return (put_termstr(term, params->check_status));
}

static void			ft_norm2(t_term *term, char *word, t_env *sub)
{
	move_it(REC, term);
	del_char(term);
	put_termstr(term, sub->value);
	return (*(word + 1) == '/' ? move_it(REC, term) : ins_char(term, '/'));
}

void				put_dol(t_term *term, t_par *params, char *word)
{
	int				size;
	t_env			*sub;

	if (*(word + 1) == '?')
		return (ft_norm1(term, params));
	else if (*word == '~')
		sub = check_sub("HOME", params->env);
	else
		sub = check_nsub(word + 1, params->env);
	if (!sub)
	{
		move_to(term, ft_strlen(word));
		return (ft_strdel(&word));
	}
	if (*word == '~')
		return (ft_norm2(term, word, sub));
	while (TL[TX] && TL[TX] != ' ' && TL[TX] != '\t')
		move_it(REC, term);
	size = ft_strlen(sub->env_name) + 1;
	while (size--)
		del_char(term);
	put_termstr(term, sub->value);
	ft_strdel(&word);
}
