/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacetild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:26:48 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 16:23:22 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static char			*get_the_line(char *line, t_env *tmp3, int *i)
{
	char			*tmp;
	char			*tmp2;

	if (!tmp3)
		return (line);
	tmp = *i > 0 ? ft_strsub(line, 0, *i) : ft_strdup("");
	tmp = ft_concat(tmp, tmp3->value, ft_strlen(tmp3->value));
	if (line[*i + 1])
		tmp2 = ft_strsub(line, *i + 1, ft_strlen(line) - *i - 1);
	else
		tmp2 = ft_strdup("");
	tmp = ft_concat(tmp, tmp2, ft_strlen(tmp2));
	ft_strdel(&line);
	ft_strdel(&tmp2);
	*i = *i + ft_strlen(tmp3->value);
	return (tmp);
}

char				*ft_replacetild(char *line, t_env **env, t_par *params)
{
	int				i;
	t_env			*tmp3;
	int				flag;

	if (!line)
		return (NULL);
	flag = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			flag ^= 1;
		if (line[i] == '~' && !flag)
			line = get_the_line(line, check_sub("HOME", env), &i);
		else
			i++;
	}
	return (line);
}
