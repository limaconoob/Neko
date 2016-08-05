/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iparams.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:04:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 07:41:26 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

/*
**	if (!((params->com = (t_com**)malloc(sizeof(t_com*)))))
**		shell_error(Malloc, "com in iparams");
**	if (!((params->user = (t_user**)malloc(sizeof(t_user*)))))
**		shell_error(Malloc, "user in iparams");
**	params->user = iuser(params);
**	params->com = rcomm(params);
*/

static void			term_kflags(t_term *elem)
{
	if (!((elem->kflags = (t_kflag*)malloc(sizeof(t_kflag)))))
		shell_error(Malloc, "kflags in kflags");
	elem->kflags->zitat = 0;
	elem->kflags->lzitat = 0;
	elem->kflags->zitate = 0;
	elem->kflags->klammern = 0;
	elem->kflags->haken = 0;
	elem->kflags->akkolade = 0;
	elem->lflags = 0;
}

static t_term		*iterm(void)
{
	t_term			*elem;
	struct winsize	w;

	if (!((elem = (t_term*)malloc(sizeof(t_term)))))
		shell_error(Malloc, "elem in iterm");
	elem->caps = term_init();
	ioctl(0, TIOCGWINSZ, &w);
	get_size(w.ws_col, w.ws_row, NULL);
	elem->wide = 0;
	elem->prompt = NULL;
	elem->x = 0;
	elem->y = 0;
	elem->line = NULL;
	elem->cutter = NULL;
	elem->curs_y = 0;
	term_kflags(elem);
	return (elem);
}

static t_par		*all_malloc(t_par *params)
{
	if (!((params = (t_par*)malloc(sizeof(t_par)))))
		shell_error(Malloc, "params in iparams");
	if (!((params->env = (t_env**)malloc(sizeof(t_env*)))))
		shell_error(Malloc, "env in iparams");
	if (!((params->path = (t_path**)malloc(sizeof(t_path*)))))
		shell_error(Malloc, "path in iparams");
	if (!((params->logs = (t_log**)malloc(sizeof(t_log*)))))
		shell_error(Malloc, "logs in iparams");
	if (!((params->ncom = (t_ncom**)malloc(sizeof(t_ncom*)))))
		shell_error(Malloc, "ncom in iparams");
	return (params);
}

t_par				*iparams(char **envp)
{
	static t_par	*params = NULL;

	params = all_malloc(params);
	params->lcpy = NULL;
	params->term = iterm();
	params->check_status = ft_strdup("0");
	params->exec_path = getcwd(NULL, 4096);
	params->env = renv(params->env, envp);
	params->path = rpath(params);
	params->log_path = ft_concat(getcwd(NULL, 4096), "/.config/.logs", 14);
	params->logs = rlogs(params, params->log_path);
	get_size(-1, -1, params);
	return (params);
}
