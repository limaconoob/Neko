/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_afterword.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 07:36:24 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/14 08:48:11 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				clear_afterword(t_term *term)
{
	int				i;
	char			*tmp;

	while (TX < term->size && !ft_isspace(TL[TX]))
		move_it(REC, term);
	while (TX && !ft_isspace(TL[TX - 1]))
		del_char(term);
}
