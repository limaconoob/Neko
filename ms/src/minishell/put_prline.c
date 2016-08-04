/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 20:56:15 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 06:11:22 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void				put_prline(t_term *term)
{
	ft_putchar('\n');
	if (term->caps)
		term->curs_y = term_coord() - 1 + term->wide;
	ft_putstr(term->prompt);
	ft_putstr(term->line);
	move_it(0, term);
}
