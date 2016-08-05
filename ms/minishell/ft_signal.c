/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 08:06:42 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 07:40:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/ioctl.h>

static int			ft_flag(pid_t mutter)
{
	static int		flag = 0;

	if (mutter < 0)
		flag = mutter;
	else
		return (flag);
	return (0);
}

static void			mutter_sig(int sig)
{
	struct winsize	w;

	if (sig == SIGTSTP)
		signal(sig, SIG_IGN);
	else if (sig == SIGINT)
		put_newprompt(NULL, -1);
	else if (sig == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &w);
		get_size(w.ws_col, w.ws_row, NULL);
	}
	else if (sig == SIGFPE)
		exit(SIGFPE);
}

static void			tochter_sig(int sig)
{
	if (sig == SIGINT)
	{
		kill(0, sig);
		ft_putchar('\n');
		signal(SIGINT, SIG_IGN);
	}
	else if (sig == SIGTSTP)
		signal(sig, SIG_IGN);
	else if (sig == SIGCHLD)
		signal(SIGINT, SIG_DFL);
}

void				ft_signal(pid_t mutter)
{
	if (mutter > 0)
	{
		signal(SIGWINCH, mutter_sig);
		signal(SIGINT, mutter_sig);
		signal(SIGFPE, mutter_sig);
		signal(SIGTSTP, mutter_sig);
	}
	else if (mutter == 0)
	{
		signal(SIGINT, tochter_sig);
		signal(SIGCHLD, tochter_sig);
		signal(SIGTSTP, tochter_sig);
	}
	else if (mutter < 0)
		(void)ft_flag(mutter);
}
