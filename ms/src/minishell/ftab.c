/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 04:43:21 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 04:52:09 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void					ftab(char **tab)
{
	int					i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_strdel(&(tab[i]));
	ft_strdel(&(tab[i]));
	free(tab);
}
