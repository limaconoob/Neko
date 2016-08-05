/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 05:47:22 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/22 00:45:13 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static int			ft_norm2(char **line, char *buf, int ret)
{
	int				i;

	i = 0;
	while (buf[i] != '\n' && i < ret)
		i++;
	*line = ft_concat(*line, buf, i);
	return (i);
}

static char			*ft_norm3(char **line, char *get)
{
	int				i;

	i = 0;
	while (get[i] && get[i] != '\n')
		i++;
	*line = ft_concat(NULL, get, i);
	return (ft_concat(get, NULL, i));
}

int					get_next_line(int fd, char **line)
{
	static char		*get = NULL;
	int				ret;
	int				i;
	char			buf[BUFF_SIZE];

	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	*line = NULL;
	i = 0;
	if (get && *get && (get = ft_norm3(line, get)))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = ft_norm2(line, buf, ret);
		if (i + 1 < ret && (get = ft_concat(get, &buf[i] + 1, ret - i - 1)))
			return (1);
		else if (buf[i] == '\n')
			return (1);
	}
	return (*line ? 1 : ret);
}
