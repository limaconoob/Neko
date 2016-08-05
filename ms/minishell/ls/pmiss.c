/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmiss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 07:38:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:58:14 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

void				pmiss(char **av)
{
	int				i;
	struct stat		sb;

	i = -1;
	while (av[++i])
	{
		if (!(*av[i]))
			ls_error(Fts_open, "fts_open");
		if (lstat(av[i], &sb) == -1)
			ls_warning(Missingfile, av[i]);
	}
}
