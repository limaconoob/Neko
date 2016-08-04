/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:50:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/22 06:39:39 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				put_name(char *put)
{
	char			*name;

	name = ft_strjoin(put, ":");
	ft_putendl(name);
	ft_strdel(&name);
}
