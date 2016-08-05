/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_termstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 09:14:25 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 10:24:50 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void				put_termstr(t_term *term, char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str != '\n' && *str != '\t')
			ins_char(term, *str);
		else
			ins_char(term, ' ');
		str++;
	}
}
