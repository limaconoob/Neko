/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:27:27 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 21:37:14 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

static int			ft_swap_times(char **av, int i, time_t *times)
{
	time_t			stock;

	stock = times[i];
	times[i] = times[i + 1];
	times[i + 1] = stock;
	i = ft_swap_str2(av, i);
	return (i);
}

static int			ft_nano(char **av, int i, time_t *times)
{
	struct stat		sb;
	time_t			stock;
	time_t			k;

	lstat(av[i], &sb);
	stock = sb.st_mtimespec.tv_nsec;
	lstat(av[i + 1], &sb);
	k = sb.st_mtimespec.tv_nsec;
	if (stock < k)
		i = ft_swap_times(av, i, times);
	else if (stock == k && ft_strcmp(av[i], av[i + 1]) > 0)
		i = ft_swap_times(av, i, times);
	else
		i++;
	return (i);
}

void				ft_sort_time2(int ac, char **av, time_t *time)
{
	time_t			stock;
	int				i;

	i = 0;
	while (i < ac - 1)
	{
		if (time[i] == time[i + 1])
			i = ft_nano(av, i, time);
		else if (time[i] > time[i + 1])
			i++;
		else
			i = ft_swap_times(av, i, time);
	}
}
