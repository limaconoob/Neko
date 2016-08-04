/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmanp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 12:22:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/19 20:59:24 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>

void			pmanp(char **av, char *exec_path)
{
	int			i;
	int			fd;
	char		*tmp;
	char		*line;

	i = 0;
	if (tab_size(av) == 1)
	{
		ft_putendl("Fehler (manp): Benutzung: manp [Anweisung ...]");
		return ;
	}
	while (av[++i])
	{
		tmp = ft_strjoin(av[i], ".man");
		fd = open(ft_strjoin(exec_path, tmp), O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Keine manuelle Eingabe für ");
			ft_putendl(av[i]);
			continue ;
		}
		while (get_next_line(fd, &line))
			ft_putendl(line);
	}
}
