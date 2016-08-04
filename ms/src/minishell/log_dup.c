/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 09:12:53 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 07:08:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

t_log				*log_dup(t_log *log)
{
	t_log			*dupl;

	if (!((dupl = (t_log*)malloc(sizeof(t_log)))))
		shell_error(Malloc, "dupl in log_dup");
	if (log->line)
		dupl->line = ft_strdup(log->line);
	else
		dupl->line = NULL;
	dupl->log_number = log->log_number;
	dupl->next = NULL;
	dupl->last = NULL;
	return (dupl);
}
