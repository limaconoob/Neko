/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ienv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:13:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 04:08:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

t_env			*ienv(char *line)
{
	t_env		*stock;
	int			i;

	i = 0;
	if (!((stock = (t_env*)malloc(sizeof(t_env)))))
		shell_error(Malloc, "stock in renv");
	while (line[i] && line[i] != '=')
		i++;
	stock->env_name = ft_strsub(line, 0, i);
	if (line[i + 1])
		stock->value = ft_strdup(&(line[i + 1]));
	else
		stock->value = ft_strdup("");
	stock->next = NULL;
	return (stock);
}
