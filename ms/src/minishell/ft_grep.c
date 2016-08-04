/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:11:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/25 04:34:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>
#include <sysexits.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int		line_check(char **tmp, int size)
{
	int			i;
	int			len;

	i = -1;
	len = ft_strlen(tmp[0]);
	while (tmp[2][++i])
	{
		if (!NCMP(&(tmp[2][i]), tmp[0], len))
		{
			if (!size)
				return (0);
			if (size > 3)
			{
				ft_putstr(tmp[1]);
				ft_putchar(':');
			}
			ft_putendl(tmp[2]);
			return (0);
		}
	}
	return (1);
}

static int		ft_find(int fd, char *pattern, char *name, int size)
{
	int			check;
	char		*line;
	int			k;
	char		*tmp[3];

	tmp[0] = pattern;
	tmp[1] = name;
	check = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			continue ;
		tmp[2] = line;
		check = line_check(tmp, size);
		ft_strdel(&line);
	}
	return (check);
}

static int	file_error(char *av)
{
	int		k;

	k = ft_isdir(av);
	if (k == -3)
	{
		ft_putstr(av);
		ft_putendl(": Kein Datei oder Ordner");
		return (EX_OSFILE);
	}
	else
	{
		ft_putstr(av);
		ft_putendl(": Zugang ist verboten");
		return (EX_NOPERM);
	}
}

static int	grep_error(char *av, int flag, char *pattern)
{
	ft_putstr("Fehler (ft_grep): ");
	if (!flag)
		return (file_error(av));
	else if (flag == 2)
	{
		ft_putchar('[');
		ft_putstr(pattern);
		ft_putstr("] in [");
		ft_putstr(av);
		ft_putendl("]: Kein Patternwort gefunden");
		return (EX_PROTOCOL);
	}
	else if (flag == 3)
	{
		ft_putendl("Benutzung: ft_grep [Patternwort] [Datei ...]");
		return (EX_NOINPUT);
	}
	return (flag);
}

int				get_error(char **av)
{
	int			i;
	int			ret;
	int			fd;

	if (tab_size(av) < 3)
		return (grep_error(NULL, 3, NULL));
	i = 1;
	ret = 0;
	while (av[++i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
		{
			ret = grep_error(av[i], 0, NULL);
			continue ;
		}
		ret = ft_find(fd, av[1], av[i], 0) ? grep_error(av[i], 2, av[1]) : ret;
		(void)close(fd);
	}
	return (ret);
}

void			ft_grep(char **av)
{
	int			i;
	int			fd;
	int			size;

	if ((i = get_error(av)))
		exit(i);
	i = 1;
	size = tab_size(av);
	while (av[++i])
	{
		fd = open(av[i], O_RDONLY);
		ft_find(fd, av[1], av[i], size);
		(void)close(fd);
	}
}
