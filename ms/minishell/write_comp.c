/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 22:33:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 22:44:03 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/stat.h>

static int			ft_norm1(t_dir *dir, t_comp *co, int k, t_term *term)
{
	char			*tmp;
	struct stat		sb;

	tmp = ft_strjoin(dir->name, *(dir->files[co->i]));
	if (co->j)
		del_size(term, co->j);
	put_termstr(term, *(dir->files[co->i]) + k);
	co->j = LEN(*(dir->files[co->i])) - k;
	if (lstat(tmp, &sb) > -1 && ISDIR)
	{
		ins_char(term, '/');
		co->j += 1;
	}
	co->i++;
	ft_strdel(&tmp);
	return (co->j);
}

static int			check_dir(t_comp *co, t_dir *dir, char *word, t_term *term)
{
	int				k;
	char			***files;

	files = dir->files;
	co->tmp = last_char(word, '/') > -1 ? ft_strrchr(word, '/') + 1 : word;
	k = last_char(word, '/') > -1 ? LEN(co->tmp) : LEN(word);
	while (files[co->i])
	{
		if (COMP && !ISNOTMAIN)
			return (ft_norm1(dir, co, k, term));
		co->i++;
	}
	if (co->check)
	{
		co->i = 0;
		co->check = 0;
		return (check_dir(co, dir, word, term));
	}
	return (co->j);
}

int					write_comp(char *word, t_dir *dir, t_comp *co, t_term *te)
{
	if (co->flag)
	{
		co->i = 0;
		co->j = 0;
		co->check = 1;
		return (0);
	}
	co->check = 1;
	co->j = check_dir(co, dir, word, te);
	return (co->j);
}
