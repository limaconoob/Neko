/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 09:31:46 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 07:15:09 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ls_error(int type, char *prob)
{
	ft_putstr("Fehler (ft_ls): ");
	if (type == Usage || type == Usagelong)
	{
		ft_putstr("Verbotene Option -- ");
		if (type == Usage)
			write(1, prob, 1);
		else
			write(1, prob, ft_strlen(prob));
		ft_putstr("\nBenutzung: ./ft_ls [-1Ralrt] ");
		ft_putendl("[Datei ...]");
		return ;
	}
	write(1, prob, ft_strlen(prob));
	write(1, ": ", 2);
	if (type == Malloc)
		ft_putstr("Malloc dürft nicht Gedächtnis zu behalten");
	else if (type == Opendir)
		ft_putstr("Könnte nicht diese Ordner öffnen");
	else if (type == Stat)
		ft_putstr("Stat ist scheiterten");
	else if (type == Fts_open)
		ft_putstr("Kein Datei oder Ordner");
	ft_putendl("\n(Aufgabe abgebrochen)");
}
