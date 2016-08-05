/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:36:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/16 09:06:18 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*iscom(char *av)
{
	static char	*tab[13] = {"env", "cd", "exit", "setenv", "unsetenv", \
		"help", "log", "ft_grep", "ft_ls", "manp", "clear", "echo", NULL};
	int			i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strcmp(av, tab[i]))
			return (tab[i]);
	}
	return (NULL);
}
