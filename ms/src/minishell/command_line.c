/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 15:40:05 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 21:13:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static void			get_fleche(t_term *term, char *buf)
{
	if (buf[2] == REC || buf[2] == LIN)
		move_it(buf[2], term);
	else if (buf[2] == TOP || buf[2] == UNT)
		get_history(NULL, term, buf[2]);
	else if (buf[5] == TOP || buf[5] == UNT)
		move_it(buf[5], term);
}

static void			get_term(char *buf, t_term *term, t_par *params)
{
	static int		flag = 0;

	if (ft_isprint(*buf) || *buf == DEL || *buf == 27)
		flag = 1;
	if (*buf == DEL)
		del_char(term);
	else if (*buf == TAB)
	{
		auto_comp(term, flag, params);
		flag = 0;
	}
	else if (ft_isprint(*buf))
		ins_char(term, *buf);
	else if (*buf == 27)
		get_fleche(term, buf);
}

static void			get_tline(t_par *params)
{
	static char		buf[9];

	ft_bzero(buf, 9);
	while (read(0, buf, 8) && *buf != '\n')
	{
		get_size(-1, -1, params);
		if ((!buf[1] && !buf[2]) || *buf == 27)
			get_term(buf, TERM, params);
		ft_bzero(buf, 9);
	}
	if (params->term->line || (TERM->cutter && *buf == '\n'))
	{
		if (TERM->line)
			TERM->cutter = ft_concat(TERM->cutter, TERM->line, TERM->size);
		if (ft_getbrack(params))
		{
			TERM->cutter = add_char(TERM->cutter, '\n');
			ft_strdel(&(TERM->line));
			return (get_tline(params));
		}
	}
}

static void			write_log(t_par *params)
{
	int				fd;

	push_log(params, params->term->cutter);
	fd = open(params->log_path, O_WRONLY | O_APPEND);
	if (fd > -1)
	{
		ft_putendl_fd(params->term->cutter, fd);
		(void)close(fd);
	}
}

char				**command_line(t_par *params)
{
	struct stat		sb;

	wait(NULL);
	put_newprompt(params, 0);
	if (params->lcpy)
		flcpy(params->lcpy);
	params->lcpy = log_cpy(params->logs, TERM);
	get_history(params->lcpy, NULL, -1);
	get_tline(params);
	while (params->term->x < params->term->size)
		move_it(REC, params->term);
	ft_putchar('\n');
	write_log(params);
	params->term->cutter = ft_replacedol(TERM->cutter, params->env, params);
	if (lstat(".", &sb) == -1)
		reset_cd(params->env);
	return (ft_strsplit2(params->term->cutter, ';'));
}
