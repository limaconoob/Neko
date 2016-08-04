/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 07:03:10 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 02:48:48 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

t_dir				*isdir(char *word)
{
	char			*str;

	str = get_dirpart(word);
	if (!ft_isdir(str))
		return (idir2(str));
	else if (last_char(str, '/') == -1)
	{
		ft_strdel(&str);
		return (idir2(ft_strdup("./")));
	}
	ft_strdel(&str);
	return (NULL);
}
