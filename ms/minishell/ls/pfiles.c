/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 02:50:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/10 19:56:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <stdlib.h>

void		pfiles(char ***files, char *name, int *options)
{
	int			cur_file;
	int			content;

	cur_file = -1;
	while (files[++cur_file])
	{
		if (options[l])
			gstat(files[cur_file], name);
		content = 0;
		while (files[cur_file][++content])
			ft_putstr(files[cur_file][content]);
		write(1, *files[cur_file], ft_strlen(*files[cur_file]));
		if (*files[cur_file] || files[cur_file][7])
			write(1, "\n", 1);
	}
}
