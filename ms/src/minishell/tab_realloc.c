/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:00:21 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/09 20:26:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

char			**tab_realloc(char **tab, int new_size, int range)
{
	char		**tmp;
	int			i;

	if (!((tmp = (char**)malloc(sizeof(char*) * (new_size + 1)))))
		shell_error(Malloc, "tmp in tab_realloc");
	i = 0;
	while (i < new_size && tab[i])
	{
		tmp[i] = tab[i];
		i++;
	}
	if (i < new_size)
	{
		while (i < new_size)
			tmp[i++] = ft_strnew(range);
		tmp[i] = NULL;
	}
	return (tmp);
}
