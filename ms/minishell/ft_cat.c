/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:11:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/07 05:22:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void			mutter_sig(int sig)
{
	if (sig == SIGINT)
		signal(sig, SIG_DFL);
}

static void			error_cat(char *av)
{
	char			*tmp;
	struct stat		sb;

	ft_putstr("ft_cat: ");
	if (lstat(av, &sb) == -1)
	{
		ft_putstr(av);
		ft_strdel(&av);
		ft_putendl(": Kein Datei oder Ordner");
	}
	else
	{
		if ((tmp = get_dirpart(av)) && access(tmp, X_OK))
		{
			ft_putstr(tmp);
			ft_strdel(&tmp);
			ft_putendl(": Zugang ist verboten");
		}
		else
		{
			ft_putstr(av);
			ft_strdel(&av);
			ft_putendl(": Kein Datei oder Ordner");
		}
	}
}

static void			ft_norm(void)
{
	char			*line;

	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
}

void				ft_cat(char **av)
{
	int				i;
	int				fd;
	int				ret;
	char			line[1024];

	signal(SIGINT, mutter_sig);
	if (!av[1])
		ft_norm();
	i = 0;
	while (av[++i])
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			error_cat(av[i]);
		while ((ret = read(fd, line, 1024)) > 0)
		{
			line[ret] = '\0';
			ft_putstr(line);
		}
		close(fd);
	}
	exit(EXIT_SUCCESS);
}
