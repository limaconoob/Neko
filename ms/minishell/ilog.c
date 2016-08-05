/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:48:12 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/14 05:36:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

t_log			*ilog(char *line, int log_number)
{
	t_log		*logger;
	int			i;
	int			quote;

	if (!((logger = (t_log*)malloc(sizeof(t_log)))))
		shell_error(Malloc, "log in ilog");
	i = 0;
	quote = 0;
	while (line[i] && ((line[i] != ' ' && line[i] != '\n') || quote))
	{
		if (line[i] == '\"')
			quote ^= 1;
		i++;
	}
	logger->log_number = log_number;
	logger->log_attempt = 0;
	logger->line = ft_strdup(line);
	logger->log_exec = ft_strsub(line, 0, i);
	if (line[i])
		logger->log_args = ft_strdup(&(line[i + 1]));
	else
		logger->log_args = NULL;
	logger->next = NULL;
	return (logger);
}
