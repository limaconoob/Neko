/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 05:46:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 02:14:52 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static int				*iopt(int *options)
{
	options[0] = 0;
	options[1] = 0;
	options[2] = 1;
	options[3] = 0;
	options[4] = 0;
	options[5] = 0;
	return (options);
}

t_dir					*get_dir(char *word, t_dir *dir)
{
	int					options[6];

	if (dir)
		dir = del_dir(dir);
	dir = isdir(word);
	if (dir)
	{
		gdir(dir, iopt(options));
		dir->files = ft_dtri(dir, options);
	}
	return (dir);
}
