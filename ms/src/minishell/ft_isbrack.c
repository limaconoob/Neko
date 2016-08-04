/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbrack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:28:17 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 06:34:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				ft_isbrack(char c, t_term *term)
{
	if (c == '\"' && !KF->zitat && !KF->lzitat)
		term->kflags->zitate ^= 1;
	else if (c == '\'' && !KF->zitate && !KF->lzitat)
		term->kflags->zitat ^= 1;
	else if (c == '`' && !KF->zitate && !KF->zitat)
		term->kflags->lzitat ^= 1;
	if (!QFLAG)
	{
		if (c == '(')
			term->kflags->klammern += 1;
		else if (c == ')')
			term->kflags->klammern -= 1;
		else if (c == '[')
			term->kflags->haken += 1;
		else if (c == ']')
			term->kflags->haken -= 1;
		else if (c == '{')
			term->kflags->akkolade += 1;
		else if (c == '}')
			term->kflags->akkolade -= 1;
	}
}
