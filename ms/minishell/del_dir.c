/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 05:46:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/25 05:44:48 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

t_dir			*del_dir(t_dir *dir)
{
	if (dir->files)
		ffiles(&(dir->files));
	if (dir->name)
		ft_strdel(&(dir->name));
	free(dir);
	dir = NULL;
	return (dir);
}
