/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:57:20 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/18 08:16:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

static char		**hfile(int size, char *arg)
{
	char		**file;

	file = (char**)malloc(sizeof(char*) * size);
	if (!file)
		ls_error(Malloc, "file in ifile");
	file[size - 1] = NULL;
	*file = ft_strdup(arg);
	return (file);
}

char			**ifile(char *arg, struct stat sb, int *options)
{
	char		**file;

	if (options[l] && ISLNK)
		file = hfile(9, arg);
	else if (options[l])
		file = hfile(8, arg);
	else
		file = hfile(2, arg);
	return (file);
}
