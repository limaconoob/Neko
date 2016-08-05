/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 06:37:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 07:06:47 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/wait.h>

void				ft_wait(t_par *params, pid_t father)
{
	int				status;

	if (waitpid(father, &status, WUNTRACED | WCONTINUED) == -1)
		shell_error(Waitpid, NULL);
	ft_strdel(&(params->check_status));
	if (WIFEXITED(status))
		params->check_status = ft_itoa(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		params->check_status = ft_itoa(WTERMSIG(status));
	else if (WIFSTOPPED(status))
		params->check_status = ft_itoa(WSTOPSIG(status));
	else
		params->check_status = ft_itoa(0);
}
