/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 08:21:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/18 11:04:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>

void				move_it(int way, t_term *term)
{
	if (way == REC)
		move_right(term);
	else if (way == LIN)
		move_left(term);
	else if (way == TOP)
		move_up(term);
	else if (way == UNT)
		move_down(term);
	if (!term->caps)
		return ;
	ft_putstr("\033[");
	ft_putnbr(term->curs_y + 1);
	ft_putchar(';');
	ft_putnbr(term->curs_x + 1);
	ft_putchar('H');
}
