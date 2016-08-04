/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:38:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/14 08:56:29 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void		shell_warning(int type, char *prob)
{
	ft_putstr("\nWarnung: ");
	if (type != ExtraFlag)
		ft_putstr(prob);
	if (type == ExtraFlag)
	{
		ft_putstr("So viele '");
		ft_putchar(*(prob + 1));
		ft_putstr("' für jeder '");
		ft_putchar(*prob);
		ft_putstr("' in diese Anweisung");
		ft_putendl("\n(Aufgabe abgebrochen)");
		return ;
	}
	ft_putendl("\n(Aufgabe geht weiter)");
}
