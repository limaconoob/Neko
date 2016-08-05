/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:00:04 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/16 09:26:26 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				ft_echo(char **av)
{
	int				i;
	int				size;

	i = 0;
	size = tab_size(av);
	while (++i < size)
	{
		if (av[i])
			ft_putstr(av[i]);
		if (i + 1 < size)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
