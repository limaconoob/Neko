/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 20:31:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 03:44:38 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>
#include <sys/stat.h>

int					ft_isdir(char *str)
{
	struct stat		sb;
	char			*tmp;

	if (!str)
		return (-4);
	tmp = get_dirpart(str);
	if (stat(tmp, &sb) == -1)
	{
		ft_strdel(&tmp);
		return (-3);
	}
	if (!ISDIR)
	{
		ft_strdel(&tmp);
		return (-2);
	}
	else if (access(tmp, X_OK) || access(tmp, R_OK))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	return (0);
}
