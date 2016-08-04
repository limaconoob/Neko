/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_av.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 20:21:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/24 07:53:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

char				**get_av(t_par *params, int first_log)
{
	static t_ncom	**ncom;

	if (!first_log)
	{
		set_shlvl(params->env);
		if (!((ncom = (t_ncom**)malloc(sizeof(t_ncom*)))))
			shell_error(Malloc, "ncom in get_av");
		*ncom = NULL;
	}
	if (!*ncom)
		*ncom = ncommands(ncom, command_line(params));
	else
		*ncom = kick_ncom(ncom);
	if (*ncom)
	{
		if ((*ncom)->av && *((*ncom)->av) && !CMP(*((*ncom)->av), "exit"))
			do_exit((*ncom)->av);
		else if ((*ncom)->av && *((*ncom)->av) && !((*ncom)->iscom))
			env_check(params, params->env, (*ncom)->av);
	}
	else
		return (get_av(params, 1));
	return ((*ncom)->av);
}
