/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:26:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 21:40:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>

static void			ft_sort_reverse(int ac, char **av)
{
	char			*tmp;
	int				i;

	i = -1;
	while (++i < ac / 2)
	{
		tmp = av[i];
		av[i] = av[ac - i - 1];
		av[ac - i - 1] = tmp;
	}
}

static void			ft_sort_alpha(int ac, char **av)
{
	int				i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) <= 0)
			i++;
		else
			i = ft_swap_str2(av, i);
	}
}

void				ft_tri(char **file_names, int i, int *options)
{
	int				m;
	time_t			*times;
	struct stat		sb;

	m = -1;
	if (options[t])
	{
		if (!(times = (time_t *)malloc(sizeof(time_t) * (i - 1))))
			ls_error(Malloc, NULL);
		while (++m < i)
		{
			if (lstat(file_names[m], &sb) == -1)
			{
				times[m] = 0;
				continue ;
			}
			times[m] = sb.st_mtime;
		}
		ft_sort_time2(i, file_names, times);
	}
	else
		ft_sort_alpha(i, file_names);
	pmiss(file_names);
	if (options[r])
		ft_sort_reverse(i, file_names);
}
