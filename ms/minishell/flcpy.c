/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flcpy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 22:46:41 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 23:33:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

void				flcpy(t_log **logs)
{
	t_log			*log;
	t_log			*tmp;

	if (!(*logs))
		return (free(logs));
	log = *logs;
	while (log->log_number)
	{
		ft_strdel(&(log->line));
		tmp = log->next;
		free(log);
		log = tmp;
	}
	ft_strdel(&(log->line));
	free(log);
	free(logs);
}
