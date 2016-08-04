/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacedol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:26:48 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/30 21:22:18 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"

static char			*get_the_line2(char *line, char *status, int *i)
{
	char			*tmp;
	char			*tmp2;

	tmp = *i > 0 ? ft_strsub(line, 0, *i) : ft_strdup("");
	if (line[*i + 2])
		tmp2 = ft_strsub(line, *i + 2, ft_strlen(line) - *i - 2);
	else
		tmp2 = ft_strdup("");
	tmp = ft_concat(tmp, status, ft_strlen(status));
	tmp = ft_concat(tmp, tmp2, ft_strlen(tmp2));
	ft_strdel(&line);
	ft_strdel(&tmp2);
	*i = *i + ft_strlen(status) - 1;
	return (tmp);
}

static char			*get_the_line(char *line, t_env *tmp3, int *i)
{
	char			*tmp;
	char			*tmp2;
	int				k;

	if (!tmp3)
		return (line);
	tmp = *i > 0 ? ft_strsub(line, 0, *i) : ft_strdup("");
	tmp = ft_concat(tmp, tmp3->value, ft_strlen(tmp3->value));
	k = ft_strlen(tmp3->env_name);
	if (line[k + *i + 1])
		tmp2 = ft_strsub(line, k + *i + 1, ft_strlen(line) - k - *i - 1);
	else
		tmp2 = ft_strdup("");
	tmp = ft_concat(tmp, tmp2, ft_strlen(tmp2));
	ft_strdel(&line);
	ft_strdel(&tmp2);
	*i = *i + k - 1;
	return (tmp);
}

char				*ft_replacedol(char *line, t_env **env, t_par *params)
{
	int				i;
	t_env			*tmp3;
	int				flag;

	if (!line)
		return (NULL);
	flag = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\'')
			flag ^= 1;
		if (line[i] == '$' && line[i + 1] && line[i + 1] != '?' && !flag)
			line = get_the_line(line, check_sub(&line[i + 1], env), &i);
		else if (line[i] == '$' && line[i + 1] && line[i + 1] == '?' && !flag)
			line = get_the_line2(line, params->check_status, &i);
	}
	return (ft_replacetild(line, env, params));
}
