/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:35:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 08:06:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>

void				regprocess(t_par *params, int *first_log)
{
	pid_t			father;
	static char		**av = NULL;

	father = fork();
	if (father > 0)
	{
		ft_wait(params, father);
		ft_signal(father);
		if (*first_log)
			set_termkappa();
		av = get_av(params, *first_log);
		set_termkappa();
		*first_log = 1;
	}
	ft_signal(0);
	if (father == 0)
	{
		if (av && *first_log)
			do_exec(tabenv(params->env), av, params);
		exit(EXIT_SUCCESS);
	}
}
