/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlogs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:37:42 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 04:21:05 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void		log_fill(t_par *params, int fd)
{
	int			cur_log;
	char		*line;
	t_log		*logger;

	logger = NULL;
	cur_log = 1;
	while (get_next_line2(fd, &line))
	{
		if (*(params->logs))
		{
			logger->next = ilog(line, cur_log++);
			logger = logger->next;
		}
		else
		{
			logger = ilog(line, cur_log++);
			*(params->logs) = logger;
		}
	}
}

t_log			**rlogs(t_par *params, char *log_path)
{
	int			fd;

	*(params->logs) = NULL;
	fd = open(log_path, O_RDONLY);
	if (fd == -1)
		fd = open(log_path, O_CREAT | O_EXCL);
	else
		log_fill(params, fd);
	if (*(params->logs))
		*(params->logs) = ft_list_reverse2(params->logs);
	if (fd > -1)
		(void)close(fd);
	return (params->logs);
}
