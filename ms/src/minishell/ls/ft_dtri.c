/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:26:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 21:19:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_tri nimmt ein char*** und rückkehrt eine ordnete Wortliste
**	von diesem char***.
*/

#include "ft_ls.h"
#include <stdlib.h>
#include <sys/stat.h>

static void			ft_sort_reverse(int ac, char ***av)
{
	char			**tmp;
	int				i;

	i = -1;
	while (++i < ac / 2)
	{
		tmp = av[i];
		av[i] = av[ac - i - 1];
		av[ac - i - 1] = tmp;
	}
}

static void			ft_sort_alpha(int ac, char ***av)
{
	int				i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_strcmp(*(av[i]), *(av[i + 1])) <= 0)
			i++;
		else
			i = ft_swap_str(av, i);
	}
}

char				***ft_dtri(t_dir *dir, int *options)
{
	int				m;
	time_t			*times;
	struct stat		sb;
	char			*name;

	m = -1;
	if (options[t])
	{
		if (!(times = (time_t *)malloc(sizeof(time_t) * dir->nb_files)))
			ls_error(Malloc, NULL);
		while (++m < dir->nb_files)
		{
			name = ft_strjoin(dir->name, *(dir->files[m]));
			lstat(name, &sb);
			times[m] = sb.st_mtime;
			free(name);
		}
		ft_sort_time(dir->nb_files, dir->files, times, dir->name);
		free(times);
	}
	else
		ft_sort_alpha(dir->nb_files, dir->files);
	if (options[r])
		ft_sort_reverse(dir->nb_files, dir->files);
	return (dir->files);
}
