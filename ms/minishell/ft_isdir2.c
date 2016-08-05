/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 20:31:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 03:50:12 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <unistd.h>
#include <sys/stat.h>

int					ft_isdir2(char *str)
{
	struct stat		sb;

	if (stat(str, &sb) == -1)
		return (-3);
	else if (!ISDIR)
		return (-2);
	else if (access(str, X_OK) || access(str, R_OK))
		return (-1);
	return (0);
}
