/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 08:43:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/13 09:27:39 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>

static void			put_log(t_log *log)
{
	ft_putstr(log->log_exec);
	write(1, " | ", 3);
	if (log->log_args)
		ft_putstr(log->log_args);
	write(1, "\n", 1);
	log = log->next;
}

static void			put_all(t_log **logs)
{
	t_log			*log;

	log = *logs;
	while (log)
	{
		put_log(log);
		log = log->next;
	}
	*logs = ft_list_reverse2(logs);
}

static int			check_log(t_log **logs, char *av)
{
	t_log			*log;
	int				push;

	log = *logs;
	push = 1;
	while (log)
	{
		if (!ft_strcmp(av, log->log_exec))
		{
			if (push)
				ft_putchar('\n');
			push = 0;
			put_log(log);
		}
		log = log->next;
	}
	return (push);
}

void				plog(t_log **logs, char **av)
{
	int				i;

	*logs = ft_list_reverse2(logs);
	if (!av[1])
		return (put_all(logs));
	i = 0;
	while (av[++i])
	{
		ft_putstr(av[i]);
		ft_putchar(':');
		if (check_log(logs, av[i]))
			ft_putendl(" No matches found.");
		if (av[i + 1])
			write(1, "\n", 1);
	}
	*logs = ft_list_reverse2(logs);
}
