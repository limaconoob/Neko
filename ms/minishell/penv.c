/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   penv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 08:18:15 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/10 21:27:12 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <unistd.h>

void		penv(t_env **env)
{
	t_env	*put;

	if (!env || !(*env))
		return ;
	*env = ft_list_reverse(env);
	put = *env;
	while (put)
	{
		ft_putstr(put->env_name);
		write(1, "=", 1);
		ft_putendl(put->value);
		put = put->next;
	}
	*env = ft_list_reverse(env);
}
