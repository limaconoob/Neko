/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:25:33 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 22:41:35 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>

static char			*the_dir(t_term *term, int start, int size)
{
	char			*str;
	int				i;

	str = ft_strsub(term->line, start, size);
	i = ft_isdir2(str);
	if (!i && str[size - 1] != '/')
	{
		ins_char(term, '/');
		return (add_char(str, '/'));
	}
	else
		return (str);
}

static char			*get_word(t_term *term, t_par *params)
{
	int				i;
	int				start;
	int				size;

	while (TX && ISNOSPA && ISNODOL)
		move_it(LIN, term);
	if (TL[TX] == '$' && TL[TX + 1] == '?')
		return ("$?");
	else if (TL[TX] == '~')
		return (ft_strsub(TL, TX, TX + 2));
	start = TX;
	size = 0;
	while (TL[start + size] && ISNOSP)
		size++;
	move_to(term, size);
	if (size)
		return (the_dir(term, start, size));
	return (NULL);
}

static void			norm1(t_comp *co, char *word, t_term *term)
{
	if (co->flag)
	{
		if (co->stock)
			ft_strdel(&(co->stock));
		co->dir = get_dir(word, co->dir);
		if (co->dir)
		{
			co->k = put_comp(co->dir, word, term);
			write_comp(NULL, NULL, co, term);
		}
		co->stock = word;
	}
	else if (!(co->flag) && co->dir && co->k > -3)
	{
		ft_strdel(&word);
		write_comp(co->stock, co->dir, co, term);
	}
}

static void			norm2(t_comp *co, char **word, t_par *params, t_term *term)
{
	if (co->k == -1)
	{
		*word = get_word(term, params);
		if (co->stock)
			ft_strdel(&(co->stock));
		co->dir = get_dir(*word, co->dir);
		co->stock = *word;
		co->k = -4;
	}
	else if (co->k == -4)
	{
		ft_strdel(word);
		co->k = put_comp(co->dir, co->stock, term);
	}
	if (co->k == -5 && !(co->flag))
		ft_strdel(word);
}

void				auto_comp(t_term *term, int flag, t_par *params)
{
	char			*word;
	static t_comp	co[1];

	if (!term->line)
		return (put_termstr(term, "    "));
	word = get_word(term, params);
	if (!word && !begin_space(term->line, TX))
		return (put_termstr(term, "    "));
	if (word && (*word == '$' || *word == '~'))
	{
		if (co->dir)
			co->dir = del_dir(co->dir);
		co->j = 0;
		return (put_dol(term, params, word));
	}
	co->flag = flag;
	norm1(co, word, term);
	norm2(co, &word, params, term);
}
