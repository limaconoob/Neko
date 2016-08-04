/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termkappa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 05:09:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/16 08:53:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <termios.h>

void				set_termkappa(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag ^= ~(ICANON);
	term.c_lflag ^= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return ;
}
