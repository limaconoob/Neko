/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:55:37 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 10:30:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void			push_log(t_par *params, char *line)
{
	t_log		*new_log;
	t_log		*logger;
	int			i;

	logger = *(params->logs);
	if (!line)
		return ;
	else if (!logger)
		new_log = ilog(line, 0);
	else
	{
		new_log = ilog(line, logger->log_number + 1);
		new_log->next = logger;
	}
	i = -1;
	while (new_log->line[++i])
		if (new_log->line[i] == '\n')
			new_log->line[i] = ' ';
	*(params->logs) = new_log;
}
