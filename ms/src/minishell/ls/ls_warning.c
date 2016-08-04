/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_warning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 09:31:46 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 05:56:52 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>

void	ls_warning(int type, char *prob)
{
	ft_putstr("Warnung (ft_ls): ");
	write(1, prob, ft_strlen(prob));
	ft_putstr(": ");
	if (type == Missingfile)
		ft_putendl("Kein Datei oder Ordner");
	else if (type == Permission)
		ft_putendl("Zugang ist verboten");
	else if (type == Fd)
		ft_putendl("Schlecht Datei-descriptor");
}
