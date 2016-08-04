/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 06:48:29 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 22:36:42 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

void			put_prompt(char *prompt, t_par *params)
{
	if (params->term->caps)
		params->term->curs_y = term_coord() - 1 + params->term->wide;
	params->term->curs_x = ft_strlen(prompt);
	if (params->term->prompt)
		ft_strdel(&(params->term->prompt));
	params->term->prompt = ft_strdup(prompt);
	params->term->x = 0;
	params->term->wide = 0;
	params->term->size = 0;
	params->term->y = 0;
	params->term->begin_x = ft_strlen(prompt);
	ft_putstr(prompt);
}
