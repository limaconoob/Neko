/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:48:23 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/13 10:07:47 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

char			**tabenv(t_env **env)
{
	t_env		*stock;
	char		*tek;
	int			nb_env;
	char		**tab;

	stock = *env;
	nb_env = 0;
	while (stock)
	{
		nb_env++;
		stock = stock->next;
	}
	if (!((tab = (char**)malloc(sizeof(char*) * (nb_env + 1)))))
		shell_error(Malloc, "tab in tabenv");
	tab[nb_env] = NULL;
	stock = *env;
	while (stock)
	{
		tek = ft_strjoin(stock->env_name, "=");
		tek = ft_concat(tek, stock->value, ft_strlen(stock->value));
		tab[--nb_env] = tek;
		stock = stock->next;
	}
	return (tab);
}
