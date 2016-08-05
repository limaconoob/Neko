/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 01:57:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/24 21:30:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>

int					term_init(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (0);
	term.c_lflag ^= ~(ICANON);
	term.c_lflag ^= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);
	return (1);
}
