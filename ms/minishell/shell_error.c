/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:41:51 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/24 18:26:10 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <sysexits.h>

static void		msg(char *msg, int exit_code)
{
	ft_putendl(msg);
	exit(exit_code);
}

void			shell_error(int type, char *prob)
{
	ft_putchar(type == Access || type == MissingFile ? 0 : '\n');
	ft_putstr("Fehler: ");
	ft_putstr(prob);
	if (type == MissingFile)
		msg(": Kein Datei oder Ordner", EX_OSFILE);
	else if (type == Access)
		msg(": Zugang ist verboten", EX_NOPERM);
	else if (type == Malloc)
		msg(": Malloc dürft nicht Gedächtnis zu behalten", EX_OSERR);
	else if (type == TermInit)
		msg("TermKappa: Variable TERM ist nicht verfügbar", EX_CONFIG);
	exit(EXIT_FAILURE);
}
