/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:08:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:03:46 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

char		*gtime(time_t tek)
{
	char	*get;
	char	*tmp;
	time_t	add;

	add = time(NULL);
	get = ft_strdup(ctime(&tek) + 3);
	if (tek <= add && add - tek < 15894000)
	{
		get[13] = ' ';
		get[14] = '\0';
		return (get);
	}
	else
	{
		get[7] = ' ';
		get[8] = '\0';
		tmp = ft_strdup(ctime(&tek) + 19);
		tmp[5] = ' ';
		tmp[6] = '\0';
		return (ft_strjoin(get, tmp));
	}
}
