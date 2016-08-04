/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:38:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/26 10:38:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

t_ncom				*incom(char *multi)
{
	t_ncom			*new;
	int				i;
	char			**av;

	av = ft_splitspaces(multi);
	if (av)
	{
		i = -1;
		while (av[++i])
			av[i] = ft_del_quote(av[i]);
	}
	ft_strdel(&multi);
	if (!((new = (t_ncom*)malloc(sizeof(t_ncom)))))
		shell_error(Malloc, "new in incom");
	new->av = av;
	if (av)
		new->iscom = iscom(av[0]) ? 0 : 1;
	else
		new->iscom = 1;
	new->next = NULL;
	return (new);
}
