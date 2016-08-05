/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_solo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:59:28 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 09:04:03 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/stat.h>

static int			ft_norm0(t_term *term, char *files)
{
	struct stat		sb;

	put_termstr(term, files);
	if (stat(files, &sb) > -1 && ISDIR)
	{
		ins_char(term, '/');
		return (2);
	}
	return (4);
}

static int			ft_norm1(t_term *term, char *word, char *files)
{
	struct stat		sb;
	char			*tmp;

	clear_afterslash(term);
	put_termstr(term, files);
	tmp = get_dirpart(word);
	tmp = ft_concat(tmp, files, LEN(files));
	if (stat(tmp, &sb) > -1 && ISDIR)
	{
		ft_strdel(&tmp);
		ins_char(term, '/');
		return (2);
	}
	ft_strdel(&tmp);
	return (4);
}

static int			ft_norm2(t_term *term, char *files)
{
	struct stat		sb;

	clear_afterword(term);
	put_termstr(term, files);
	if (stat(files, &sb) > -1 && ISDIR)
	{
		ins_char(term, '/');
		return (2);
	}
	return (4);
}

int					put_solo(char ***files, char *word, int k, t_term *term)
{
	char			*tmp2;

	tmp2 = last_char(word, '/') > -1 ? ft_strrchr(word, '/') + 1 : NULL;
	while (*files)
	{
		if (k == LEN(word) - 1)
			return (ft_norm0(term, **files));
		else if (k != -1 && !ft_strncmp(tmp2, **files, LEN(tmp2)))
			return (ft_norm1(term, word, **files));
		else if (!ft_strncmp(word, **files, LEN(word)))
			return (ft_norm2(term, **files));
		files++;
	}
	return (0);
}
