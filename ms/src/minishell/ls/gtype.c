/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtype.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 05:32:52 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 22:03:55 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include <stdlib.h>

static void		get_mod(mode_t *tek, mode_t mod)
{
	int		i;

	i = 3;
	while (--i >= 0)
	{
		tek[i] = mod % 8;
		mod = mod / 8;
	}
}

static void		let_mod(mode_t mod, char *mode)
{
	mode_t	tek[3];
	int		i;
	int		u;

	i = -1;
	u = -1;
	get_mod(tek, mod);
	while (++i < 3)
	{
		if (tek[i] - 4 >= 0 && (tek[i] = tek[i] - 4) >= 0)
			mode[++u] = 'r';
		else
			mode[++u] = '-';
		if (tek[i] - 2 >= 0 && (tek[i] = tek[i] - 2) >= 0)
			mode[++u] = 'w';
		else
			mode[++u] = '-';
		if (tek[i] - 1 >= 0)
			mode[++u] = 'x';
		else
			mode[++u] = '-';
	}
}

static char		*type_mask(mode_t mod, char *str)
{
	if (!(mod - S_IFWHT))
		*str = 'w';
	else if (!(mod - S_IFSOCK))
		*str = 's';
	else if (!(mod - S_IFLNK))
		*str = 'l';
	else if (!(mod - S_IFREG))
		*str = '-';
	else if (!(mod - S_IFBLK))
		*str = 'b';
	else if (!(mod - S_IFDIR))
		*str = 'd';
	else if (!(mod - S_IFCHR))
		*str = 'c';
	else if (!(mod - S_IFIFO))
		*str = 'p';
	else
		*str = '?';
	return (str);
}

char			*gtype(struct stat sb)
{
	char		*str;
	mode_t		mode;

	if (!(str = (char*)malloc(13)))
		ls_error(Malloc, "str in gtype");
	mode = sb.st_mode;
	mode |= 4095;
	mode -= 4095;
	str = type_mask(mode, str);
	let_mod(sb.st_mode, &(str[1]));
	str[10] = ' ';
	str[11] = ' ';
	str[12] = '\0';
	return (str);
}
