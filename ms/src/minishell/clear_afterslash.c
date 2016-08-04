/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_afterslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 07:36:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/24 07:44:30 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				clear_afterslash(t_term *term)
{
	int				i;
	char			*tmp;

	while (TX < term->size && !ft_isspace(TL[TX]))
		move_it(REC, term);
	while (TX && TL[TX - 1] != '/')
		del_char(term);
}
