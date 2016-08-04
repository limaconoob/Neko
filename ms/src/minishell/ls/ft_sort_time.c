/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:27:27 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:55:27 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

static int			ft_swap_times(char ***av, int i, time_t *times)
{
	time_t			stock;

	stock = times[i];
	times[i] = times[i + 1];
	times[i + 1] = stock;
	i = ft_swap_str(av, i);
	return (i);
}

static int			ft_nano(char ***av, int i, char *nam, time_t *times)
{
	struct stat		sb;
	time_t			stock;
	time_t			k;
	char			*name;

	name = ft_strjoin(nam, *(av[i]));
	lstat(name, &sb);
	stock = sb.st_mtimespec.tv_nsec;
	free(name);
	name = ft_strjoin(nam, *(av[i + 1]));
	lstat(name, &sb);
	free(name);
	k = sb.st_mtimespec.tv_nsec;
	if (stock < k)
		i = ft_swap_times(av, i, times);
	else if (stock == k && ft_strcmp(*(av[i]), *(av[i + 1])) > 0)
		i = ft_swap_times(av, i, times);
	else
		i++;
	return (i);
}

void				ft_sort_time(int ac, char ***av, time_t *time, char *name)
{
	time_t			stock;
	int				i;

	i = 0;
	while (i < ac - 1)
	{
		if (time[i] == time[i + 1])
			i = ft_nano(av, i, name, time);
		else if (time[i] > time[i + 1])
			i++;
		else
			i = ft_swap_times(av, i, time);
	}
}
