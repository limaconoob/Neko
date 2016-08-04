/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 01:48:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:02:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ffiles(char ****files)
{
	int		cur_file;
	int		content;

	cur_file = -1;
	while ((*files)[++cur_file])
	{
		content = 0;
		while ((*files)[cur_file][++content])
			ft_strdel(&((*files)[cur_file][content]));
		ft_strdel(&((*files)[cur_file][content]));
		ft_strdel(&(*((*files)[cur_file])));
		free((*files)[cur_file]);
		(*files)[cur_file] = NULL;
	}
	free((*files)[cur_file]);
	(*files)[cur_file] = NULL;
	free(*files);
	*files = NULL;
}
