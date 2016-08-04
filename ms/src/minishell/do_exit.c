/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 01:47:18 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 07:24:20 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

static void			error_exit(char *flag)
{
	if (!flag)
		ft_putendl("Fehler (exit): So viele Argumente");
	else
	{
		ft_putstr("Fehler (exit): ");
		ft_putstr(flag);
		ft_putendl(": Schlecht Argument");
	}
	ft_putendl("Benutzung: exit [value]");
}

void				do_exit(char **av)
{
	int				k;

	if (tab_size(av) > 2)
		return (error_exit(NULL));
	k = av[1] ? ft_strisnum(av[1]) : 0;
	if (k < 0)
		return (error_exit(av[1]));
	set_termkappa();
	exit(k);
}
