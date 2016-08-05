/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/18 10:45:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

static int		cursor_pos(char *buf)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = 2;
	write(1, "\e[6n", 5);
	read(1, buf, 9);
	while (buf[0] == 27 && buf[1] == 91 && ft_isdigit(buf[i]))
		tmp = (tmp * 10) + buf[i++] - '0';
	return (tmp);
}

int				term_coord(void)
{
	int			ret;
	char		buf[9];

	ft_bzero(buf, 9);
	return (cursor_pos(buf));
}
