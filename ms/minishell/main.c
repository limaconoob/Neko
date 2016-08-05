/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:49:41 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 03:52:38 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <signal.h>
#include <sys/wait.h>

int					main(int argc, char **argv, char **envp)
{
	static t_par	*params = NULL;
	static int		first_log = 0;

	(void)argc;
	(void)argv;
	params = iparams(envp);
	if (!TERM->caps)
		do_protect(params);
	while (PROCESS)
		regprocess(params, &first_log);
	return (0);
}
