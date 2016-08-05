/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirpart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 01:13:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/24 20:30:22 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

char			*get_dirpart(char *word)
{
	int			i;
	char		*tmp;

	i = last_char(word, '/');
	if (i == -1)
		return (NULL);
	tmp = ft_strsub(word, 0, i + 1);
	return (tmp);
}
