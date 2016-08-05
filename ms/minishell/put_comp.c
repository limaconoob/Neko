/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 05:50:37 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 09:03:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/stat.h>

static int			get_solo(char ***files, char *word, int k)
{
	int				unique;

	unique = 2;
	while (*files)
	{
		if (!(*word))
			unique--;
		else if (k != -1 && !NCMP(WORD, **files, LEN(WORD)))
			unique--;
		else if (!ft_strncmp(word, **files, LEN(word)))
			unique--;
		if (!unique)
			break ;
		files++;
	}
	return (unique);
}

static int			put_files(int first, char *files, char *dir)
{
	struct stat		sb;
	int				k;

	if (!first)
		ft_putchar('\n');
	ft_putstr(files);
	k = ft_strlen(files);
	if (lstat(dir, &sb) > -1 && (ISDIR || ISLNK))
	{
		ft_putchar(ISDIR ? '/' : '@');
		k++;
	}
	if (k < 8)
		ft_putstr("\t\t");
	else if (k < 16)
		ft_putstr(" \t");
	else
		ft_putchar(' ');
	if (first == 2)
		first = 0;
	else
		first++;
	return (first);
}

static int			the_files(char *word, t_dir *dir, int k, t_term *term)
{
	int				first;
	char			***files;
	char			*tmp;
	char			*tmp2;

	first = 0;
	files = dir->files;
	tmp2 = last_char(word, '/') > -1 ? ft_strrchr(word, '/') + 1 : NULL;
	while (*files)
	{
		if (ISNTMAIN && files++)
			continue ;
		tmp = ft_strjoin(dir->name, **files);
		if (k == LEN(word) - 1)
			first = put_files(first, **files, tmp);
		else if (k != -1 && !ft_strncmp(tmp2, **files, LEN(tmp2)))
			first = put_files(first, **files, tmp);
		else if (!ft_strncmp(word, **files, LEN(word)))
			first = put_files(first, **files, tmp);
		ft_strdel(&tmp);
		files++;
	}
	put_prline(term);
	return (0);
}

int					put_comp(t_dir *dir, char *word, t_term *term)
{
	int				o;
	int				p;
	int				k;

	if (!dir)
		return (0);
	if (!word)
		return (the_files("./", dir, 2, term));
	k = last_char(word, '/');
	o = get_solo(dir->files, word, k);
	p = 0;
	if (o == 1 && k == -1)
		p = put_solo(dir->files, word, k, term);
	if (o == 1 && k != -1)
		p = put_solo(dir->files, word, k, term);
	else if (o == 2)
		return (-3);
	if (p == 2)
		return (-1);
	else if (p == 1)
		return (-2);
	else if (p == 4)
		return (-5);
	return (the_files(word, dir, k, term));
}
