/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 03:51:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 07:34:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/wait.h>

static int			ext(char **av)
{
	if (tab_size(av) == 2 && ft_strisnum(av[1]) >= 0)
		return (1);
	else if (tab_size(av) == 1)
		return (1);
	return (0);
}

void				do_protect(t_par *params)
{
	char			**get;
	char			**av;
	pid_t			father;

	get = tabenv(params->env);
	while (get_next_line(0, &(params->term->line)))
	{
		father = fork();
		if (father > 0)
			ft_wait(params, father);
		if (father == 0)
		{
			av = ft_strsplit(params->term->line, ' ');
			command_exec(params, params->env, av);
			if (!ft_strcmp(av[0], "exit") && ext(av))
				break ;
			do_exec(get, av, params);
		}
	}
	(void)term_init();
	if (tab_size(av) < 3 && !ft_strcmp(av[0], "exit"))
		do_exit(av);
	exit(ft_atoi(params->check_status));
}
