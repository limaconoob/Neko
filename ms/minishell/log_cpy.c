/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:25:49 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 07:59:44 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <stdlib.h>

static t_log		*cpy_init(t_term *term, t_log *log)
{
	t_log			*cpy;

	if (!((cpy = (t_log*)malloc(sizeof(t_log)))))
		shell_error(Malloc, "cpy in cpy_init");
	cpy->log_number = log ? log->log_number + 1 : 0;
	cpy->line = NULL;
	cpy->next = NULL;
	cpy->last = NULL;
	return (cpy);
}

static void			ft_norm(t_log **logged, t_log **logger)
{
	(*logged)->next = log_dup((*logger)->next);
	((*logged)->next)->last = *logged;
	*logged = (*logged)->next;
	*logger = (*logger)->next;
}

t_log				**log_cpy(t_log **logs, t_term *term)
{
	t_log			**cpy;
	t_log			*logger;
	t_log			*logged;

	if (!logs || !(*logs))
		return (NULL);
	if (!((cpy = (t_log**)malloc(sizeof(t_log*)))))
		shell_error(Malloc, "cpy in log_cpy");
	*cpy = cpy_init(term, *logs);
	logger = *logs;
	while (logger)
	{
		if ((*cpy)->next && logger->next)
			ft_norm(&logged, &logger);
		else if ((*cpy)->next && !logger->next)
			break ;
		else if ((logged = log_dup(logger)))
		{
			(*cpy)->next = logged;
			logged->last = *cpy;
		}
	}
	if (logged && (logged->next = *cpy))
		(*cpy)->last = logged;
	return (cpy);
}
