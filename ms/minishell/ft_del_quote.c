/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 22:00:03 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 06:19:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static void			clear_flag(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
}

static char			*get_delquote(char *str, int nb_quote, int *flag)
{
	int				i;
	int				j;
	char			*tmp;

	if (!((tmp = (char*)malloc(ft_strlen(str) - nb_quote + 1))))
		shell_error(Malloc, "tmp in ft_del_quote");
	clear_flag(flag);
	i = 0;
	j = -1;
	while (str[++j])
	{
		if (str[j] == '\"' && !flag[1] && !flag[2])
			flag[0] ^= 1;
		else if (str[j] == '\'' && !flag[0] && !flag[2])
			flag[1] ^= 1;
		else if (str[j] == '`' && !flag[0] && !flag[1])
			flag[2] ^= 1;
		else if (!ft_isbrack2(str[j]) || (flag[0] | flag[1] | flag[2]))
			tmp[i++] = str[j];
	}
	ft_strdel(&str);
	tmp[i] = '\0';
	return (tmp);
}

static int			fl_set(int *flag, int get, int nb_quote)
{
	if (flag[get] == 1)
		nb_quote++;
	flag[get] ^= 1;
	return (nb_quote);
}

char				*ft_del_quote(char *str)
{
	int				nb_quote;
	int				i;
	int				flag[3];

	if (!str)
		return (NULL);
	nb_quote = 0;
	clear_flag(flag);
	i = -1;
	while (str[++i])
	{
		if (ft_isbrack2(str[i]) && !flag[0] && !flag[1] && !flag[2])
			nb_quote++;
		if (str[i] == '\"' && !flag[1] && !flag[2])
			fl_set(flag, 0, nb_quote);
		else if (str[i] == '\'' && !flag[0] && !flag[2])
			fl_set(flag, 1, nb_quote);
		else if (str[i] == '`' && !flag[0] && !flag[1])
			fl_set(flag, 2, nb_quote);
	}
	if (!nb_quote)
		return (str);
	clear_flag(flag);
	return (get_delquote(str, nb_quote, flag));
}
