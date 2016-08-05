/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 05:12:38 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/04 05:32:46 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char				*tab_line(char **tab)
{
	char			*line;

	if (!tab)
		return (NULL);
	line = NULL;
	while (*tab)
	{
		line = ft_concat(line, *tab, ft_strlen(*tab));
		tab++;
	}
	return (line);
}
