/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:02:07 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 08:08:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

void			set_path(t_par *params, char *av)
{
	t_path		*path;

	while (*(params->path))
	{
		ft_strdel(&((*(params->path))->path_name));
		path = (*(params->path))->next;
		free(*(params->path));
		*(params->path) = path;
	}
	if (!av || ft_strcmp(av, "/usr/bin:/bin:/usr/sbin:/sbin"))
	{
		ft_putendl("Warnung: Variable PATH ist jetzt ändern,");
		ft_putendl("dann einige Anweisungen wird vielleicht nicht verfügbar.");
		ft_putendl("Prüf: $> help\t-\t-\t-\t-\t-\t->  für mehr Hilfe.");
		ft_putstr("      $> setenv PATH=/usr/bin:/bin:/usr/sbin:/sbin");
		ft_putendl("\t->  für es kommt wieder.");
	}
	spath(params->path, av);
}
